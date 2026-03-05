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

	Fraction f1(100);
	std::cout << "Stored form: "
		<< f1.getNumerator()
		<< "/"
		<< f1.getDenominator()
		<< std::endl;

	Fraction fCopy(*p1);
	std::cout << "Stored form: "
		<< fCopy.getNumerator()
		<< "/"
		<< fCopy.getDenominator()
		<< std::endl;

	delete p1;

	Fraction fDec(0.75);
	std::cout << "Stored form: "
		<< fDec.getNumerator()
		<< "/"
		<< fDec.getDenominator()
		<< std::endl;

	Fraction fAdd = fCopy + fDec;

	std::cout << fCopy.getNumerator() << "/" << fCopy.getDenominator()
		<< " + " <<
		fDec.getNumerator() << "/" << fDec.getDenominator()
		<< " = " << fAdd.getNumerator() << "/" << fAdd.getDenominator()
		<< std::endl;
	

	try
	{
		Fraction fZero(1, 0);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

