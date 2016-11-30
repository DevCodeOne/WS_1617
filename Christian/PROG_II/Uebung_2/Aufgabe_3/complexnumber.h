#pragma once

class complexnumber_constructor {
	public:
		complexnumber_constructor(double real = 0, double imaginary = 0);
		double get_real() const;
		double get_imaginary() const;
	private:
		double m_real;
		double m_imaginary;
		// eigentlich
		// double m_real{0};
		// double m_imag{0};
};
// auf jeden Fall in Class Initializer benutzen damit 
// alle Primitiven initialisiert sind nur hier Ausnahme, um die Unterschiede
// aufzuzeigen


// in class initializer (equal)
class complexnumber_in_class_equal {
	public:
		double get_real() const;
		double get_imaginary() const;
	private:
		double m_real = 0;
		double m_imaginary = 0;
};

// in class initializer (braces)
class complexnumber_in_class_braces {
	public:
		double get_real() const;
		double get_imaginary() const;
	private:
		double m_real{0};
		double m_imaginary{0};
};
