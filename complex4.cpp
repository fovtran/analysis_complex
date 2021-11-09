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

int main() {
    typedef vector<complex<double>> complexVect;
    typedef vector<double> doubleVect;

    const int SIZE = 256;
    vector<doubleVect> phi_w(SIZE, doubleVect(SIZE));
    vector<complexVect> phi_k(SIZE, complexVect(SIZE));
    complex<double> i (0, 1), cmplx (0, 0);
    complex<double> temp;
    int x, y, t, k, w;
    double dk = 2.0*M_PI / (SIZE-1);
    double dt = M_PI / (SIZE-1);
    int xPos, yPos;
    double arg, arg2, arg4;
    complex<double> arg3;
    double angle;
    vector<complexVect> newImg(SIZE, complexVect(SIZE));

    for (x = 0; x < SIZE; ++x) {
        xPos = -127 + x;
        for (y = 0; y < SIZE; ++y) {
            yPos = -127 + y;
            for (t = 0; t < SIZE; ++t) {
                temp = cmplx;
                angle = dt * t;
                arg = xPos * cos(angle) + yPos * sin(angle);
                for (k = 0; k < SIZE; ++k) {
                    arg2 = -M_PI + dk*k;
                    arg3 = exp(-i * arg * arg2);
                    arg4 = abs(arg) * M_PI / (abs(arg) + M_PI);
                    temp = temp + arg4 * arg3 * phi_k[k][t];
                }
            }
            newImg[y][x] = temp;
        }
    }
}
