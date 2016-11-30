#include "complexnumber.h"

complexnumber_constructor::complexnumber_constructor(double real, double imag) : m_real(real), m_imaginary(imag) {

}

double complexnumber_constructor::get_real() const { return m_real; }
double complexnumber_constructor::get_imaginary() const { return m_real; }

double complexnumber_in_class_equal::get_real() const { return m_real; }
double complexnumber_in_class_equal::get_imaginary() const { return m_real; }

double complexnumber_in_class_braces::get_real() const { return m_real; }
double complexnumber_in_class_braces::get_imaginary() const { return m_real; }
