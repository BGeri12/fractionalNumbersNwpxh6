#include "Fraction.h"
#include <stdexcept>

Fraction::Fraction(const int numerator, const int denominator)
	: numerator{ denominator < 0 ? -numerator : numerator }
	, denominator{ denominator < 0 ? -denominator : denominator}
{
	if (this->denominator == 0)
		throw std::invalid_argument("A nevezo nem lehet nulla!");

	int commonDivisor = this->gcd(this->numerator, this->denominator);
	this->numerator /= commonDivisor;
	this->denominator /= commonDivisor;
}

int Fraction::gcd(int a, int b) const
{
	if (a < 0)
		a *= -1;

	if (b < 0)
		b *= -1;

	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}