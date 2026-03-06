#pragma once
#include<string>
#include <iostream>

class Fraction
{

public:
	Fraction(const int numerator);
	Fraction(const int numerator, const int denominator);
	Fraction(const Fraction& fraction) = default;
	Fraction(const double decimal);
	Fraction(const std::string& str);

	Fraction& operator+=(const Fraction& f);
	Fraction& operator-=(const Fraction& f);
	Fraction& operator*=(const Fraction& f);
	Fraction& operator/=(const Fraction& f);

	explicit operator int() const;
	explicit operator double() const;
	explicit operator std::string() const;
	explicit operator bool() const;

	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
	friend std::istream& operator>>(std::istream& is, Fraction& f);

	int GetNumerator() const;
	int GetDenominator() const;

private:
	int numerator;
	int denominator;
	void Simplify();
};

Fraction operator+(const Fraction& f1, const Fraction& f2);
Fraction operator-(const Fraction& f1, const Fraction& f2);
Fraction operator*(const Fraction& f1, const Fraction& f2);
Fraction operator/(const Fraction& f1, const Fraction& f2);
bool operator==(const Fraction& f1, const Fraction& f2);
bool operator!=(const Fraction& f1, const Fraction& f2);
bool operator<(const Fraction& f1, const Fraction& f2);
bool operator>(const Fraction& f1, const Fraction& f2);
bool operator<=(const Fraction& f1, const Fraction& f2);
bool operator>=(const Fraction& f1, const Fraction& f2);