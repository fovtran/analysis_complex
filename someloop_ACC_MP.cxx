#include <cstdlib>
#include <cmath>

int main(){

int count=1000000;
double *a = new double[count];

// you want OpenACC or OpenMP 4.5+.
#pragma acc parallel loop //Memory movement handled automagically
for(int i=0;i<count;i++)
  a[i] = std::sqrt(std::log(a[i])+1.0); //Tada! I'm on the GPU
  return -1;  
}
