// "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\Common7\Tools\vsdevcmd
// "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\vc\Auxiliary\Build\vcvarsall.bat" x64 8.1
// cl /EHsc trapezoidal.cpp
#include <iostream>
#include <fstream>
#include <mmsystem.h>

using namespace std;

double trapezoidal(string file){
	double x0{}, y0{}, I{};
	ifstream fin{file};
	fin>>x0>>y0;
	for (double x, y; fin>>x>>y; ){
		I+= (x-x0)*(y+y0)/2;
		x0 = x;
		y0 = y;
	}
	fin.close();
	return I;
}

int main(){
	double I=trapezoidal("data.txt");
	cout<<"Integral = "<<I<<endl;
}