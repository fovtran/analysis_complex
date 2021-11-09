//#include <mmintrin.h>  // MMX
//#include <xmmintrin.h> // SSE
#include <emmintrin.h> // SSE2
//#include <pmmintrin.h> // SSE3
//#include <tmmintrin.h> // SSSE3
//#include <smmintrin.h> // SSE4.1
//#include <nmmintrin.h> // SSE4.2
//#include <ammintrin.h> // SSE4A
//#include <wmmintrin.h> // AES
#include <immintrin.h> // AVX
//#include <x86intrin.h> // el que sea necesario

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#include <vector>

using namespace std;

struct Particle
{
    __m128 x4[128];
    __m128 y4[128];
    __m128 z4[128];
    __m128i mass4[128];
}Particle;

inline __m128i Mat4Mul(const __m128i M1)
{
    __m128i In = _mm_setr_epi32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff);

    for (unsigned int i=0; i<2; i+=1) 
    {
        //__m128i ta = _mm_load_ps(M1[i]);
        //__m128 tb = _mm_load_ps(M1[i]);
    }
        //__m128i tc = _mm_mul_ps(In, In);
        //_mm_store_ps(&c[i], tc);

    __m128i Out = _mm_setr_epi32(0x00000000, 0x00000000, 0x00000000, 0x00000000);
    return Out;
}

void normal(float* a, int N)                                                                                                                                                                                     
{                                                                                                                                                                                                                
  for (int i = 0; i < N; ++i)                                                                                                                                                                                    
    a[i] = sqrt(a[i]);                                                                                                                                                                                           
}          

void sse(float* a, int N)                                                                                                                                                                                        
{                      
  // We assume N % 4 == 0.                                                                                                                                                                                        
  int nb_iters = N / 4;                                                                                                                                                                                         
  __m128* ptr = (__m128*)a;                                                                                                                                                                                      
 
  for (int i = 0; i < nb_iters; ++i, ++ptr, a += 4)                                                                                                                                                              
    _mm_store_ps(a, _mm_sqrt_ps(*ptr));                                                                                                                                                                          
}     

void sse2(char* a, const char* b, int N)                                                                                                                                                                          
{                                                                                                                                                                                                                
  int nb_iters = N / 16;                                                                                                                                                                                         
 
  __m128i* l = (__m128i*)a;                                                                                                                                                                                      
  __m128i* r = (__m128i*)b;                                                                                                                                                                                      
 
  for (int i = 0; i < nb_iters; ++i, ++l, ++r)                                                                                                                                                                   
    _mm_store_si128(l, _mm_add_epi8(*l, *r));                                                                                                                                                                    
}

void sse2_cmp_mask(float* __restrict__ result,
         const float* __restrict__ v,
         unsigned length)
{
  __m128 zero = _mm_set1_ps(0.f);
 
  for (unsigned i = 0; i <= length - 4; i += 4)
  {
    __m128 vec = _mm_load_ps(v + i);
    __m128 mask = _mm_cmpge_ps(vec, zero);
    __m128 sqrt = _mm_sqrt_ps(vec);
    __m128 res = _mm_or_ps(_mm_and_ps(mask, sqrt),
                           _mm_andnot_ps(mask, vec));
    _mm_store_ps(result + i, res);
  }
}

int main()
{
    short array[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    cout << array[0] <<endl ; 

    const __m128i value2 = _mm_loadu_si128((__m128i*) &array[0]);
    __m128i val = Mat4Mul(value2);

    long long int ra = val[0];
    long long int rb = val[1];
    long long int rc = val[2];
    long long int rd = val[3];
    long long int re = val[4];
    long long int rf = val[5];
    long long int rg = val[6];
    long long int rh = val[7];

    float *arrq = reinterpret_cast<float*>(&val);

    for (int n=0; n<1; n++)
        std::cout << val[n] << std::endl;


    int N = 1024;

    float* a;                                                                                                                                                                                                      
    posix_memalign((void**)&a, 16,  N * sizeof(float));                                                                                                                                                            

    for (int i = 0; i < N; ++i)                                                                                                                                                                                    
        a[i] = 3141592.65358; 

    sse(a, N);
    for (int n=0; n<N; n++)
        std::cout << a[n] << std::endl;

    return 0;
}

int v1()
{
    int N = 1024;

    float* a;                                                                                                                                                                                                      
    posix_memalign((void**)&a, 16,  N * sizeof(float));                                                                                                                                                            

    for (int i = 0; i < N; ++i)                                                                                                                                                                                    
        a[i] = 3141592.65358;  

    normal(a, N);
 
    for (int i = 0; i < N; ++i)                                                                                                                                                                                    
        a[i] = 3141592.65358;                                                                                                                                                                                        
 
    sse(a, N);
    return 0;
}

std::vector<int> v2()
{    
    std::vector<int> vec;
    vec.push_back(6);
    vec.push_back(-17);
    vec.push_back(12);
    
    vec.erase(vec.begin() + 1); // Deletes the second element (vec[1])    
    vec.erase(vec.begin() + 1, vec.begin() + 3);    // Deletes the second through third elements (vec[1], vec[2])
    return vec;
}