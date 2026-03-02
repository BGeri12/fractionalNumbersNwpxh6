#include <iostream>*
#include "Fraction.h"

int main()
{
	Fraction* p1 = new Fraction(10, -5);
	std::cout << "Stored form: "
		<< (*p1).getNumerator()
		<< "/"
		<< p1->getDenominator()
		<< std::endl;
	delete p1;

	try
	{
		Fraction fZero(1, 0);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

