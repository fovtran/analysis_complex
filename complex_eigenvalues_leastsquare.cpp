#include <iostream>
#include <Eigen/Dense>
#include <complex>

using namespace Eigen;

int main()
{
    MatrixXcd A(4, 4);
    A(0,0) = std::complex<double>(3,5);
    A(1,0) = std::complex<double>(4,4);
    A(1,1) = std::complex<double>(5,3);
    A(2,0) = std::complex<double>(2,2);
    A(2,1) = std::complex<double>(3,3);
    A(2,2) = std::complex<double>(4,4);
    A(3,0) = std::complex<double>(5,3);
    A(3,1) = std::complex<double>(2,4);
    A(3,2) = std::complex<double>(4,3);
    A(3,3) = std::complex<double>(2,4);

    VectorXcd b(4);
    b(0) = std::complex<double>(3,5);
    b(1) = std::complex<double>(2,0);
    b(2) = std::complex<double>(8,2);
    b(3) = std::complex<double>(4,8);

        std::cout << "Here is the A matrix:" << std::endl;
    std::cout << A << std::endl;

        std::cout << "Here is the b vector:" << std::endl;
        std::cout << b << std::endl;

    std::cout << "The least-squares solution is:\n"

        << A.jacobiSvd(ComputeThinU | ComputeThinV).solve(b) << std::endl;

    MatrixXf A = MatrixXf::Random(3, 3);
    std::cout << "Here is the matrix A:\n" << A << std::endl;
    VectorXf b = VectorXf::Random(3);
    std::cout << "Here is the right hand side b:\n" << b << std::endl;
    std::cout << "The least-squares solution is:\n"
    << A.jacobiSvd(ComputeThinU | ComputeThinV).solve(b) << std::endl;
}// end