#include "Fraction.h"
#include <stdexcept>

Fraction::Fraction(const int numerator, const int denominator)
	: numerator(numerator)
	, denominator(denominator)
{
	if (this->denominator == 0)
		throw std::invalid_argument("A nevezõ nem lehet nulla!");

	if (this->denominator < 0){
		this->numerator *= -1;
		this->denominator *= -1;
	}
}