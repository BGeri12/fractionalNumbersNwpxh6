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

Fraction::Fraction(const std::string& str) 
{
	size_t slashPos = str.find('/');

	if (slashPos != std::string::npos)
	{
		std::string numStr = str.substr(0, slashPos);
		std::string denStr = str.substr(slashPos + 1);
		this->numerator = std::stoi(numStr);
		this->denominator = std::stoi(denStr);
	}
	else
	{
		this->numerator = std::stoi(str);
		this->denominator = 1;
	}

	if (this->denominator == 0) 
		throw std::invalid_argument("A nevezo nem lehet nulla!");

	Simplify();
}

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

Fraction::operator int() const
{
	return this->numerator / this->denominator;
}

Fraction::operator double() const
{
	return static_cast<double>(this->numerator) / this->denominator;
}

Fraction::operator std::string() const
{
	if (this->denominator == 1) 
		return std::to_string(this->numerator); 

	return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
}

Fraction::operator bool() const
{
	return this->numerator != 0;
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

bool operator==(const Fraction& f1, const Fraction& f2)
{
	return f1.GetNumerator() == f2.GetNumerator() && f1.GetDenominator() == f2.GetDenominator();
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
	return !(f1 == f2);
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	return f1.GetNumerator() * f2.GetDenominator() < f2.GetNumerator() * f1.GetDenominator();
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
	return f2 < f1;
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
	return !(f2 < f1);
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
	return !(f1 < f2);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	os << f.numerator << "/" << f.denominator;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& f)
{
	is >> f.numerator;
	is >> f.denominator;
	return is;
}

