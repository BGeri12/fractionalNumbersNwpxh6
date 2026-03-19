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

	Fraction& operator+=(const Fraction& other);
	Fraction operator+(const Fraction& other) const;
	Fraction operator-() const;
	Fraction& operator-=(const Fraction& other);
	Fraction operator-(const Fraction& other) const;
	Fraction& operator*=(const Fraction& other);
	Fraction operator*(const Fraction& other) const;
	Fraction& operator/=(const Fraction& other);
	Fraction operator/(const Fraction& other) const;

	bool operator==(const Fraction& other) const;
	bool operator!=(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator>(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;

	explicit operator int() const;
	explicit operator double() const;
	explicit operator std::string() const;
	explicit operator bool() const;

	friend std::istream& operator>>(std::istream& is, Fraction& f);

	static Fraction Parse(const std::string& input);

private:
	int numerator;
	int denominator;
	void Simplify();
};

std::ostream& operator<<(std::ostream& os, const Fraction& f);