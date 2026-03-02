#pragma once

class Fraction
{

public:
	Fraction(const int numerator);
	Fraction(const int numerator, const int denominator);
	Fraction(const Fraction& fraction);
	Fraction(const double decimal);

	int getNumerator() const;
	int getDenominator() const;

private:
	int numerator;
	int denominator;

	int gcd(int a, int b) const;
};
