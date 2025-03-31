#include <iostream>
#include "complex.hpp"

int main() {
    using cplx = ComplexNumber<float>;  // con i float
	
	float a = 1;
	float b = 2;
	float c = -2;
	
    cplx c1(a, b);
    cplx c2(a, c);

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;

    std::cout << "Somma: " << c1 + c2 << std::endl;
    std::cout << "Prodotto: " << c1 * c2 << std::endl;
	
	c1+=c2;
	std::cout << "c1+=c2: " << c1 << std::endl;
	
	c2*=c1;
	std::cout << "c2*=c1: " << c2 << std::endl;

	double x = 5;
	
    cplx c3 = c1 + x;
    std::cout << "c1 + 5: " << c3 << std::endl;

    cplx c4 = x + c1;
    std::cout << "5 + c1: " << c4 << std::endl;

    cplx c5 = c1 * x;
    std::cout << "c1 * 2: " << c5 << std::endl;

    cplx c6 = x * c1;
    std::cout << "2 * c1: " << c6 << std::endl;

    std::cout << "Coniugato di c1: " << c1.conjugate() << std::endl;
    return 0;
}
