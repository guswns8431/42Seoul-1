#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
	Awesome classa(10);
	Awesome classb(20);

	std::cout << (classa > classb) << std::endl;
	swap(classa, classb);
	std::cout << (classa > classb) << std::endl;
	std::cout << &min(classa, classb) << std::endl;
	std::cout << &max(classa, classb) << std::endl;


	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	double doubleA = 2.1;
	double doubleB = 4.2;

	std::cout << "doubleA = " << doubleA << ", doubleB = " << doubleB << std::endl;
	::swap(doubleA, doubleB);
	std::cout << "doubleA = " << doubleA << ", doubleB = " << doubleB << std::endl;
	std::cout << "min(doubleA, doubleB) = " << min(doubleA, doubleB) << std::endl;
	std::cout << "max(doubleA, doubleB) = " << ::max(doubleA, doubleB) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::string e = "chaine3";
	std::string f = "chaine3";

	std::cout << "e = " << e << ", f = " << f << std::endl;
	swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "f -> " << &f  << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << " (" << &::min(e, f) << ")" << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << " (" << &::max(e, f) << ")" << std::endl;

	return 0;
}
