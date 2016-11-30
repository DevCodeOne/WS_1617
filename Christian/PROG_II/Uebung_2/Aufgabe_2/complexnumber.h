#pragma once

class complexnumber_constructor {
	public:
		complexnumber_constructor(double real = 0, double imaginary = 0) : m_real(real), m_imaginary(imaginary) {}
		double m_real;
		double m_imaginary;
};

// in class initializer (equal)
class complexnumber_in_class_equal {
	public:
		double m_real = 0;
		double m_imaginary = 0;
};

// in class initializer (braces)
class complexnumber_in_class_braces {
	public:
		double m_real{0};
		double m_imaginary{0};
};
