#include "Fraction.h"
#include <stdexcept>
#include <numeric>

Fraction::Fraction(const int numerator, const int denominator)
	: numerator{ denominator < 0 ? -numerator : numerator }
	, denominator{ denominator < 0 ? -denominator : denominator}
{
	if (this->denominator == 0)
		throw std::invalid_argument("The denominator cannot be zero !");

	Simplify();
}

Fraction::Fraction(const int numerator) : Fraction(numerator, 1) {}

Fraction::Fraction(const double decimal) : Fraction(static_cast<int>(decimal * 1000000), 1000000) {}

void Fraction::Simplify()
{
	const int commonDivisor = std::gcd(this->numerator, this->denominator);
	this->numerator /= commonDivisor;
	this->denominator /= commonDivisor;
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
	int newNumerator = this->numerator * f.denominator + f.numerator * this->denominator;
	int commonDenominator = this->denominator * f.denominator;
	this->numerator = newNumerator;
	this->denominator = commonDenominator;
	this->Simplify();
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& f)
{
	int newNumerator = this->numerator * f.denominator - f.numerator * this->denominator;
	int commonDenominator = this->denominator * f.denominator;
	this->numerator = newNumerator;
	this->denominator = commonDenominator;
	this->Simplify();
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& f)
{
	int newNumerator = this->numerator * f.numerator;
	int commonDenominator = this->denominator * f.denominator;
	this->numerator = newNumerator;
	this->denominator = commonDenominator;
	this->Simplify();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& f)
{
	int newNumerator = this->numerator * f.denominator;
	int commonDenominator = this->denominator * f.numerator;
	this->numerator = newNumerator;
	this->denominator = commonDenominator;
	this->Simplify();
	return *this;
}

//global fv:
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