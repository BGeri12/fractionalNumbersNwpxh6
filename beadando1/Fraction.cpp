#include "Fraction.h"
#include <stdexcept>

Fraction::Fraction(const int numerator, const int denominator)
	: numerator{ denominator < 0 ? -numerator : numerator }
	, denominator{ denominator < 0 ? -denominator : denominator}
{
	if (this->denominator == 0)
		throw std::invalid_argument("The denominator cannot be zero !");

	int commonDivisor = this->gcd(this->numerator, this->denominator);
	this->numerator /= commonDivisor;
	this->denominator /= commonDivisor;
}

Fraction::Fraction(const int numerator) : Fraction(numerator, 1) {}

Fraction::Fraction(const Fraction& fraction)
	: numerator{ fraction.numerator }
	,denominator{ fraction.denominator } {}

Fraction::Fraction(const double decimal) : Fraction(static_cast<int>(decimal * 1000000), 1000000) {}

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

int Fraction::GetNumerator() const
{
	return this->numerator;
}

int Fraction::GetDenominator() const
{
	return this->denominator;
}

std::string Fraction::FracToString() const
{
	return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
}

Fraction& Fraction::operator+=(const Fraction& f)
{
	int commonDenominator = this->denominator * f.denominator;
	int newNumerator = this->numerator * f.denominator + f.numerator * this->denominator;
	*this = Fraction(newNumerator, commonDenominator);
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& f)
{
	int commonDenominator = this->denominator * f.denominator;
	int newNumerator = this->numerator * f.denominator - f.numerator * this->denominator;
	*this = Fraction(newNumerator, commonDenominator);
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& f)
{
	int newDenominator = this->denominator * f.denominator;
	int newNumerator = this->numerator * f.numerator;
	*this = Fraction(newNumerator, newDenominator);
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& f)
{
	int newDenominator = this->denominator * f.numerator;
	int newNumerator = this->numerator * f.denominator;
	*this = Fraction(newNumerator, newDenominator);
	return *this;
}

//osztályon kívüli függvények:
Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	Fraction result{ f1 };
	return result += f2;
}

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	Fraction result{ f1 };
	return result -= f2;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	Fraction result{ f1 };
	return result *= f2;
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
	Fraction result{ f1 };
	return result /= f2;
}