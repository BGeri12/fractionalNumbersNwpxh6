#pragma once

class Fraction
{

public:
	Fraction(const int numerator);
	Fraction(const int numerator, const int denominator);
	Fraction(const Fraction& fraction);
	Fraction(const double decimal);

	friend Fraction operator+(const Fraction& f1, const Fraction& f2);

	int GetNumerator() const;
	int GetDenominator() const;


private:
	int numerator;
	int denominator;

	int gcd(int a, int b) const;
};
