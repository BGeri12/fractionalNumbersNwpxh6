#pragma once

class Fraction
{

public:
	Fraction(const int numerator, const int denominator);

	int getNumerator() const;
	int getDenominator() const;

private:
	int numerator;
	int denominator;

	int gcd(int a, int b) const;
};
