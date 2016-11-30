#include <cmath>
#include <limits>
#include <sstream>

#include "complexnumber.h"
#include "simpletest.h"

bool near_zero(double val) {
	static double epsilon = std::numeric_limits<double>::epsilon();
	return std::abs(val) < epsilon;
}

bool nearly_equal(double val, double val2) {
	return near_zero(val - val2);
}

SIMPLETEST("Default Konstruktor") {
	complexnumber c; 
	if (near_zero(c.real()) && near_zero(c.imag()))
		return true;
	return false;
};

SIMPLETEST("Konstruktor nur mit real Zahl") {
	complexnumber c(0.5f); 
	if (nearly_equal(c.real(), 0.5f) && near_zero(c.imag()))
		return true;
	return false;
};

SIMPLETEST("Konstruktor mit Realanteil und Imaginaeranteil") {
	complexnumber c(0.5f, 0.25f);
	if (nearly_equal(c.real(), 0.5f) && nearly_equal(c.imag(), 0.25f))
		return true;
	return false;
};

SIMPLETEST("Konstruktor mit Realanteil und Imaginaeranteil") {
	complexnumber c(0.5f, 0.25f);
	if (nearly_equal(c.real(), 0.5f) && nearly_equal(c.imag(), 0.25f))
		return true;
	return false;
};

SIMPLETEST("Mutatoren Test") {
	complexnumber c(0.f, 0.f);
	c.real(0.5f);
	c.imag(0.25f);
	if (nearly_equal(c.real(), 0.5f) && nearly_equal(c.imag(), 0.25f))
		return true;
	return false;
};

SIMPLETEST("Prädikaten Test") {
	complexnumber c(0.f, 0.f);
	c.real(0.5f);
	if (c.is_real() && !c.is_imag()) {
		c.imag(0.5f);
		if (!c.is_real() && c.is_imag()) 
			return true;
		return false;
	}
	return false;
};

SIMPLETEST("Additionstest") {
	complexnumber c(0.f, 0.f);
	complexnumber c2(0.5f, 0.25f);

	c.add(c2);
	
	if (nearly_equal(c.real(), 0.5f) && nearly_equal(c.imag(), 0.25f))
		return true;
	return false;
};

SIMPLETEST("to_string Test") {
	complexnumber c(0.5f, 0.25f);

	std::stringstream stream;
	stream.precision(2);
	stream << c.name() << " CN[" << c.real() << ", " << c.imag() << "]";

	return stream.str() == c.to_string();
};

SIMPLETEST("Namenstest") {
	complexnumber c(0.5f, 0.25f);

	std::string result = "Zufall";

	c.name(result);

	return result == c.name();
};

SIMPLETEST("Colortest") {
	complexnumber c{0.5f, 0.25f};

	std::string color = "blue";

	c.color(color);

	return c.color() == color;
};

SIMPLETEST("SVGTest") {
	complexnumber c{0.5f, 0.5f};

	std::stringstream stream;
	stream << "<circle cx=\"" << (int) c.imag() << "\" cy=\"" << (int) c.real() << 
		"\" r=\"" << complexnumber::radius << "\" fill=\"" << c.color() << "\" />";

	return c.to_svg() == stream.str();
};

complexnumber::complexnumber(double real, double imag) : m_real(real), m_imag(imag) { } 
double complexnumber::real() const { return m_real; }
double complexnumber::imag() const { return m_imag; } 
bool complexnumber::is_real() const { return near_zero(imag()); } 
bool complexnumber::is_imag() const { return !near_zero(imag()); }
std::string complexnumber::name() const { return m_name; }
std::string complexnumber::color() const { return m_color; }

bool complexnumber::is_nearly_equal(const complexnumber &c) const {
	return nearly_equal(m_real, c.m_real) && nearly_equal(m_imag, c.m_imag);	
}

void complexnumber::real(double real) { m_real = real; }
void complexnumber::imag(double imag) { m_imag = imag; } 
void complexnumber::name(const std::string &name) { m_name = name; }
void complexnumber::color(const std::string &color) { m_color = color; }

std::string complexnumber::to_string() const {
	std::stringstream stream;
	stream.precision(2);
	stream << m_name << " CN[" << m_real << ", " << m_imag << "]";
	return stream.str();
}

std::string complexnumber::to_svg() const {
	std::stringstream stream;
	stream << "<circle cx=\"" << (int) m_imag << "\" cy=\"" << (int) m_real << 
		"\" r=\"" << complexnumber::radius << "\" fill=\"" << m_color << "\" />";
	return stream.str();
}

void complexnumber::add(const complexnumber &c) {
	m_imag += c.m_imag;
	m_real += c.m_real;
}

complexnumber complexnumber::add(const complexnumber &c1, const complexnumber &c2) {
	complexnumber result; 
	result.m_imag = c1.m_imag + c2.m_imag;
	result.m_real = c1.m_real + c2.m_real;
	return result;	
}
