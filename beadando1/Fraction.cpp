#include "Fraction.h"
#include <stdexcept>
#include <numeric>
#include <sstream>

Fraction::Fraction(const int numerator, const int denominator)
	: numerator{ denominator < 0 ? -numerator : numerator }
	, denominator{ denominator < 0 ? -denominator : denominator}
{
	if (denominator == 0)
		throw std::invalid_argument("The denominator cannot be zero !");

	Simplify();
}

Fraction::Fraction(const int numerator) : Fraction(numerator, 1) {}

Fraction::Fraction(const double decimal) : Fraction(static_cast<int>(decimal * 1000000), 1000000) {}

void Fraction::Simplify()
{
	const int commonDivisor = std::gcd(numerator, denominator);
	numerator /= commonDivisor;
	denominator /= commonDivisor;
}

Fraction& Fraction::operator+=(const Fraction& f)
{ 
	numerator = numerator * f.denominator + f.numerator * denominator;
	denominator = denominator * f.denominator;
	Simplify();
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& f)
{
	Fraction negative_f(-f.numerator, f.denominator);
	return *this += negative_f;
}

Fraction& Fraction::operator*=(const Fraction& f)
{
	numerator = numerator * f.numerator;
	denominator = denominator * f.denominator;
	Simplify();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& f)
{
	Fraction reciprocal_f(f.denominator, f.numerator);
	return *this *= reciprocal_f;
}

Fraction::operator int() const
{
	return numerator / denominator;
}

Fraction::operator double() const
{
	return static_cast<double>(numerator) / denominator;
}

Fraction::operator std::string() const
{
	if (denominator == 1) 
		return std::to_string(numerator); 

	return std::to_string(numerator) + "/" + std::to_string(denominator);
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
	int num, den;

	if (!(is >> num))
		return is;

	is >> std::ws;

	if (is.peek() == '/')
	{
		is.get();
		is >> den; 
	}
	else
		is >> den;

	if (is)
		f = Fraction(num, den);
	else
		is.setstate(std::ios::failbit);

	return is;
}

Fraction Fraction::Parse(const std::string& input)
{
	// megfelelõ formátum: "num/den"

	std::istringstream iss{ input };
	int num, den;
	char separator;

	iss >> num >> separator >> den;

	if (iss.fail() || separator != '/')
		throw std::invalid_argument(input + " was not suitable!");

	return Fraction{num, den};
}

