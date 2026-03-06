#include <iostream>
#include "Fraction.h"

int main()
{
	Fraction* p1 = new Fraction(10, -5);
	std::cout << "Stored form: "
		<< (*p1).GetNumerator()
		<< "/"
		<< p1->GetDenominator()
		<< std::endl;

	Fraction f1(100);
	std::cout << "Stored form: "
		<< f1.GetNumerator()
		<< "/"
		<< f1.GetDenominator()
		<< std::endl;

	Fraction fCopy(*p1);
	std::cout << "Stored form: "
		<< fCopy.GetNumerator()
		<< "/"
		<< fCopy.GetDenominator()
		<< std::endl;

	delete p1;

	Fraction fDec(0.75);
	std::cout << "Stored form: "
		<< fDec.GetNumerator()
		<< "/"
		<< fDec.GetDenominator()
		<< std::endl;

	Fraction fAdd = fCopy + fDec;

	std::cout << fCopy.FracToString()
		<< " + " <<
		fDec.FracToString()
		<< " = " << 
		fAdd.FracToString()
		<< std::endl;

	std::cout << fCopy.FracToString()
		<< " - " <<
		fDec.FracToString()
		<< " = " <<
		(fCopy - fDec).FracToString()
		<< std::endl;

	std::cout << fCopy.FracToString()
		<< " * " <<
		fDec.FracToString()
		<< " = " <<
		(fCopy * fDec).FracToString()
		<< std::endl;

	std::cout << fCopy.FracToString()
		<< " / " <<
		fDec.FracToString()
		<< " = " <<
		(fCopy / fDec).FracToString()
		<< std::endl;

	std::cout << "Original fCopy: " << fCopy.FracToString()
		<< "\tOriginal fDec: " << fDec.FracToString()
		<< std::endl;
	fCopy += fDec;
	std::cout << "fCopy After += : " << fCopy.FracToString() << std::endl;
	fCopy -= fDec;
	std::cout << "fCopy After -= : " << fCopy.FracToString() << std::endl;
	fCopy *= fDec;
	std::cout << "fCopy After *= : " << fCopy.FracToString() << std::endl;
	fCopy /= fDec;
	std::cout << "fCopy After /= : " << fCopy.FracToString() << std::endl;



	try
	{
		Fraction fZero(1, 0);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

