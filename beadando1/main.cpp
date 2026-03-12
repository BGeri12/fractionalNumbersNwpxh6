#include <iostream>
#include "Fraction.h"

int main()
{
	Fraction* p1 = new Fraction(10, -5);
	std::cout << "Stored form: "
		<< (*p1)
		<< std::endl;

	Fraction f1(100);
	std::cout << "Stored form: "
		<< f1
		<< std::endl;

	Fraction fCopy(*p1);
	std::cout << "Stored form: "
		<< fCopy
		<< std::endl;

	delete p1;

	Fraction fDec(0.75);
	std::cout << "Stored form: "
		<< fDec
		<< std::endl;

	Fraction fAdd = fCopy + fDec;

	std::cout << fCopy
		<< " + " <<
		fDec
		<< " = " << 
		fAdd
		<< std::endl;

	std::cout << fCopy
		<< " - " <<
		fDec
		<< " = " <<
		(fCopy - fDec)
		<< std::endl;

	std::cout << fCopy
		<< " * " <<
		fDec
		<< " = " <<
		(fCopy * fDec)
		<< std::endl;

	std::cout << fCopy
		<< " / " <<
		fDec
		<< " = " <<
		(fCopy / fDec)
		<< std::endl;

	std::cout << "Original fCopy: " << fCopy
		<< "\tOriginal fDec: " << fDec
		<< std::endl;
	fCopy += fDec;
	std::cout << "fCopy After += : " << fCopy << std::endl;
	fCopy -= fDec;
	std::cout << "fCopy After -= : " << fCopy<< std::endl;
	fCopy *= fDec;
	std::cout << "fCopy After *= : " << fCopy<< std::endl;
	fCopy /= fDec;
	std::cout << "fCopy After /= : " << fCopy<< std::endl;

	Fraction fNegative(-2, -41);
	std::cout << "Stored form: "
		<< fNegative
		<< std::endl;

	if (10 == fNegative)
		std::cout << fNegative << " is equal to 10" << std::endl;
	else
		std::cout << fNegative << " is not equal to 10" << std::endl;

	
	Fraction f2(1, 2);
	Fraction f3(3, 4);

	if (f2 >= f3)
		std::cout << f2<< " is greater or equal to" << f3 << std::endl;
	else
		std::cout << f2 << " is less than " << f3 << std::endl;

	if (f2 > f3)
		std::cout << f2 << " is greater than " << f3 << std::endl;
	else
		std::cout << f2 << " is less or equal to " << f3 << std::endl;

	if (f2 != f3)
		std::cout << f2 << " is not equal to " << f3 << std::endl;
	else
		std::cout << f2 << " somthing else " << f3 << std::endl;

	if (f2 <= f3)
		std::cout << f3 << " is greater or equal to " << f2 << std::endl;
	else
		std::cout << f3 << " is less than " << f2  << std::endl;

	if (f2 < f3)
		std::cout << f3 << " is greater than " << f2 << std::endl;
	else
		std::cout << f3 << " is less or equal to " << f2 << std::endl;

	Fraction f4(5, 2);
	int egesz = static_cast<int>(f4);
	std::cout << "Integer part of " << f4 << " is: " << egesz << std::endl;
	double tizedes = static_cast<double>(f4);  
	std::cout << "Decimal value of " << f4 << " is: " << tizedes << std::endl;
	std::string szoveg = static_cast<std::string>(f4); 
	std::cout << "String representation of " << f4 << " is: " << szoveg << std::endl;

	if (f4)
	{
		std::cout << f4 << " is true" << std::endl;
	}
	else
	{
		std::cout << f4 << " is false" << std::endl;
	}

	Fraction fStr("3/4");
	std::cout << "Stored form: "
		<< fStr
		<< std::endl;

	std::cin >> f4;
	std::cout << "You entered: " << f4 << std::endl;

	/*
	try
	{
		Fraction fZero(1, 0);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	*/
}

