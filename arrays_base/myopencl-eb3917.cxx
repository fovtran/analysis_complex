#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include <string>
#include <process.h>

#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>
#include <experimental/filesystem>

#define __CL_ENABLE_EXCEPTIONS
#if defined(__APPLE__) || defined(__MACOSX)
#include <OpenCL/cl.cpp>
#else
#include <CL/cl.h>
#include <CL/cl_ext.h>
#include <CL/cl_gl_ext.h>
#include <CL/cl_platform.h>
#include <CL/cl_d3d10_ext.h>
#endif

#include "myopencl.hxx"

using namespace std;
//using namespace cl;

namespace OpenCL
{

		static char *source_str;
		static size_t source_size;
		#define MAX_SOURCE_SIZE (0x100000)
		#define mydouble cl_double16
		#define LIST_SIZE 192000

	static int OpenCL::read_kernel(char *kernelf)
	{
		fopen_s(&fp, kernelf, "r"); // fopen secure
		if (!fp) { fprintf(stderr, "Failed to load kernel.\n"); return -1; }
		source_str = (char*)malloc(MAX_SOURCE_SIZE);
		source_size = fread( source_str, 1, MAX_SOURCE_SIZE, fp);
		fclose( fp );
		return 0;
	}

	int OpenCL::cl_compute_kernel(const char *kernelName)
	{
		int i;
		A = (float*)malloc(sizeof(float)*LIST_SIZE);
		B = (float*)malloc(sizeof(float)*LIST_SIZE);

	    for(i = 0; i < LIST_SIZE; i++) {
	        A[i] = i;
	        B[i] = LIST_SIZE - i;
	    }
		return 0;
	}


	int OpenCL::compute_kernel(const char *kernelName) {

	    cl_platform_id platform_id = NULL;
	    cl_device_id device_id = NULL;
	    cl_uint ret_num_devices;
	    cl_uint ret_num_platforms;
	    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
		printf("Platform ID: %u\n", ret);

		ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);
		printf("OpenCL CPU ID: %d\n", ret_num_devices);

	    ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);
		printf("OpenCL GPU ID: %d\n", ret_num_devices);

	    cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret);
	    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

	    cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE * sizeof(float), NULL, &ret);
	    cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE * sizeof(float), NULL, &ret);
	    cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, LIST_SIZE * sizeof(float), NULL, &ret);

	    ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(float), A, 0, NULL, NULL);
	    ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(float), B, 0, NULL, NULL);

	    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);

	    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	    cl_kernel kernel = clCreateKernel(program, kernelName, &ret);

	    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&a_mem_obj);
	    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&b_mem_obj);
	    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&c_mem_obj);

	    size_t global_item_size = LIST_SIZE; // Process the entire lists
	    size_t local_item_size = 64; // Divide work items into groups of 64
	    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);

	    float *C = (float*)malloc(sizeof(float)*LIST_SIZE);
	    ret = clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(float), C, 0, NULL, NULL);

	    // Display the result to the screen
	    //for(i = 0; i < LIST_SIZE; i++)
	        //printf("%8.0f + %5.0f = %5.14f\n", A[i], B[i], C[i]);

	    ret = clFlush(command_queue);
	    ret = clFinish(command_queue);
	    ret = clReleaseKernel(kernel);
	    ret = clReleaseProgram(program);
	    ret = clReleaseMemObject(a_mem_obj);
	    ret = clReleaseMemObject(b_mem_obj);
	    ret = clReleaseMemObject(c_mem_obj);
	    ret = clReleaseCommandQueue(command_queue);
	    ret = clReleaseContext(context);
	    free(A);
	    free(B);
	    free(C);
	    return 0;
	}
} // namespace
