#include <cmath>
#include <limits>

#include "complexnumber.h"

bool near_zero(double val) {
	static double epsilon = std::numeric_limits<double>::epsilon();
	return std::abs(val) < epsilon;
}

complexnumber::complexnumber(double real, double imag) : m_real(real), m_imag(imag) { }
double complexnumber::real() const { return m_real; }
double complexnumber::imag() const { return m_real; }
void complexnumber::real(double real) { m_real = real; }
void complexnumber::imag(double imag) { m_imag = imag; }
bool complexnumber::is_real() const { return near_zero(imag()); }
bool complexnumber::is_imag() const { return !near_zero(imag()); }

void complexnumber::add(complexnumber c) {
	m_imag += c.m_imag;
	m_real += c.m_real;
}

complexnumber complexnumber::add(complexnumber c1, complexnumber c2) {
	complexnumber result; 
	result.m_imag = c1.m_imag + c2.m_imag;
	result.m_real = c1.m_real + c2.m_real;
	return result;	
}
