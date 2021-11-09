// >cl /EHsc complex.cpp /std:c++latest
#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <vector>
#include <math.h>
#include <cmath>
#include <complex>
#include <complex.h>

using namespace std;

#define __float double


int main()
{
    float f1 = 1.0;
    complex<float> fc=2.0 + 3.0i;
    // 4 Bytes
    printf("sizeof(float)         : %d\n", sizeof(float));
    // 8 Bytes (realer und imaginärer Teil)
    printf("sizeof(float complex) : %d\n", sizeof(complex<float>));
    // Ausgabe vom Real- und Imaginärteil
    printf("%f + %f\n", creal(fc), cimag(fc));
    return EXIT_SUCCESS;
}
