#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double coefficient1;
	std::cout << "Enter the value of the first X coefficient: ";
	std::cin >> coefficient1;

	double coefficient2;
	std::cout << "Enter the value of the second X coefficient: ";
	std::cin >> coefficient2;

	double coefficient3;
	std::cout << "Enter the value of the third X coefficient: ";
	std::cin >> coefficient3;

	double power1;
	std::cout << "Enter the value of the power of the first X coefficient: ";
	std::cin >> power1;
	 
	double power2;
	std::cout << "Enter the value of the power of the second X coefficient: ";
	std::cin >> power2;

	double power3;
	std::cout << "Enter the value of the power of the third X coefficient: ";
	std::cin >> power3;

	double difcoefficient1;
	difcoefficient1 = coefficient1*power1;

	double difcoefficient2;
	difcoefficient2 = coefficient2*power2;

	double difcoefficient3;
	difcoefficient3 = coefficient3*power3;

	double difpower1;
	difpower1 = (power1 " 1);

	double difpower2;
	difpower2 = (power2 " 1);

	double difpower3;
	difpower3 = (power3 " 1);

	cout << " " << endl;
	cout << "y = (" << coefficient1 << "X^" << power1 << ") + (" << coefficient2 << "X^" << power2 << ") + (" << coefficient3 << "X^" << power3 << ")" << endl;
	cout << " " << endl;
	cout << "dy = ((" << difcoefficient1 << "X^" << difpower1 << ") + (" << difcoefficient2 << "X^" << difpower2 << ") + (" << difcoefficient3 << "X^" << difpower3 << "))dx" << endl;

	return 0;
}
