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

Fraction& Fraction::operator+=(const Fraction& other)
{ 
	numerator = numerator * other.denominator + other.numerator * denominator;
	denominator *= other.denominator;
	Simplify();
	return *this;
}

Fraction Fraction::operator+(const Fraction& other) const
{
	Fraction result { *this };
	return result += other;
}

Fraction operator+(const int number, const Fraction& f)
{
	return f + number;
}

Fraction Fraction::operator-() const
{
	return Fraction{ -numerator, denominator };
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this += -other;
}

Fraction Fraction::operator-(const Fraction& other) const
{
	Fraction result{ *this };
	return result -= other;
}

Fraction operator-(const int number, const Fraction& f)
{
	return -f + number;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	numerator *= other.numerator;
	denominator *= other.denominator;
	Simplify();
	return *this;
}

Fraction Fraction::operator*(const Fraction& other) const
{
	Fraction result{ *this };
	return result *= other;
}

Fraction operator*(const int number, const Fraction& f)
{
	return f * number;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	Fraction reciprocal_f{other.denominator, other.numerator};
	return *this *= reciprocal_f;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	Fraction result{ *this };
	return result /= other;
}

Fraction operator/(const int number, const Fraction& f)
{
	return Fraction{ number } / f;
}

bool Fraction::operator==(const Fraction& other) const
{
	return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction& other) const
{
	return !(*this == other);
}

Fraction::operator double() const
{
	return static_cast<double>(numerator) / denominator;
}

bool Fraction::operator<(const Fraction& other) const
{
	return static_cast<double>(*this) < static_cast<double>(other);
}

bool Fraction::operator>(const Fraction& other) const
{
	return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const
{
	return !(other < *this);
}

bool Fraction::operator>=(const Fraction& other) const
{
	return !(*this < other);
}

Fraction::operator int() const
{
	return numerator / denominator;
}

Fraction::operator bool() const
{
	return numerator != 0;
}

Fraction::operator std::string() const
{
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	os << static_cast<std::string>(f);
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
	Fraction result;

	if (iss >> result)
		return result;
	else
		throw std::invalid_argument(input + " was not suitable!");
}




