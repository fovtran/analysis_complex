// >cl /EHsc complex.cpp /std:c++latest
#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <vector>
#include <math.h>
#include <cmath>
#include <complex>
#include <complex.h>

using namespace std;

int main(int argc, char *argv[]){
	
std::complex<double> x=3.0-3.0i;
std::complex<double> y=2.0+4.0i;

cout.precision(3);
cout<<"x="<<x<<" y="<<y<<'\n';
cout<<" OR x real="<<real(x)<<" x imagine="<<imag(x)<<"\n\n";

complex<double> sum = x + y;
cout<<"The sum: x + y = "<<sum<<'\n';

complex<double> difference = x - y;
cout<<"The difference: x - y = "<<difference<<'\n';

complex<double> product = x * y;
cout<<"The product: XY = "<<product<<'\n';

complex<double> quotient = x / y;
cout<<"The quotient: x / y = "<<quotient<<'\n';

complex<double> conjugate = conj(x);
cout<<"The conjugate of x = "<<conjugate<<'\n';

complex<double> reciprocal = 1.0/x;
cout<<"The reciprocal of x = "<<reciprocal<<'\n';

complex<double> exponential =exp(x);
cout<<"The exponential  of x = "<<exponential<<'\n';

double magnitude=2.0,phase=45;
cout<<"magintude = "<<magnitude<<" phase = "<< phase<<" degrees\n";
complex<double> pol= std::polar(2.0,(M_PI/180.0)*phase);
cout<<"The polar: x , y = "<<pol<<'\n';

return 0;
}
