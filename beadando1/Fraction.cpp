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

Fraction Fraction::Parse(const std::string& str) 
{
	size_t slashPos = str.find('/');
	std::string numStr, denStr;

	if (slashPos != std::string::npos)
	{
		numStr = str.substr(0, slashPos);
		denStr = str.substr(slashPos + 1);
	}
	else
	{
		numStr = str;
		denStr = "1";
	}

	int parsedNum = 0;
	int parsedDen = 1;

	try
	{
		size_t numParsedLen = 0;
		size_t denParsedLen = 0;

		parsedNum = std::stoi(numStr, &numParsedLen);
		parsedDen = std::stoi(denStr, &denParsedLen);

		if (numParsedLen != numStr.length() || denParsedLen != denStr.length()) {
			throw std::invalid_argument("Incorrect non-numeric characters in fraction !");
		}
	}
	catch (const std::exception& e)
	{
		throw std::invalid_argument("The specified text cannot be formatted!");
	}

	return Fraction(parsedNum, parsedDen);
}

void Fraction::Simplify()
{
	const int commonDivisor = std::gcd(this->numerator, this->denominator);
	this->numerator /= commonDivisor;
	this->denominator /= commonDivisor;
}

Fraction& Fraction::operator+=(const Fraction& f)
{ 
	this->numerator = this->numerator * f.denominator + f.numerator * this->denominator;
	this->denominator = this->denominator * f.denominator;
	this->Simplify();
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& f)
{
	Fraction negative_f(-f.numerator, f.denominator);
	return *this += negative_f;
}

Fraction& Fraction::operator*=(const Fraction& f)
{
	this->numerator = this->numerator * f.numerator;
	this->denominator = this->denominator * f.denominator;
	this->Simplify();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& f)
{
	Fraction reciprocal_f(f.denominator, f.numerator);
	return *this *= reciprocal_f;
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
	return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
	return !(f1 == f2);
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	return f1.numerator * f2.denominator < f2.numerator * f1.denominator;
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

