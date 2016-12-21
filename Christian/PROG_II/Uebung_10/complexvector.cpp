#include <sstream>

#include "complexvector.h"
#include "simpletest.h"
#include "debug.h"
#include "serialgenerator.h"

SIMPLETEST("complexvector Konstruktor") {
	complexnumber c = {};
	complexnumber c2 = {10, 10};
	complexvector cv(c, c2);
	
	return c.is_nearly_equal(cv.begin()) && c2.is_nearly_equal(cv.end());
};

std::ostream &operator<<(std::ostream &os, const complexvector &v) {
	return os << "[ " << v.begin() << ", " << v.end();
}

bool operator==(const complexvector &v, const complexvector &v2) {
	return (v.begin() == v2.begin()) && (v.end() == v2.end());
}

bool operator!=(const complexvector &v, const complexvector &v2) {
	return !(v == v2);
}

complexvector::complexvector(const complexnumber &begin, const complexnumber &end) 
	: m_begin(begin), m_end(end), m_serialnr(create_object_serial()) { }

complexvector::complexvector(const complexvector &v) : complexvector(v.m_begin, v.m_end) { }

complexvector &complexvector::operator=(const complexvector &v) {
	this->m_begin = v.m_begin;
	this->m_end = v.m_end;

	return *this;
}
complexvector::~complexvector() { }

complexnumber complexvector::begin() const { return m_begin; }

complexnumber complexvector::end() const { return m_end; }

void complexvector::color(const std::string &color) {
	m_color = color;
}

std::string complexvector::color() const {
	return m_color;
}

std::string complexvector::to_svg() const {
	std::stringstream stream;
	stream << m_begin.to_svg();
	stream << m_end.to_svg();
	stream << "<line x1=\"" << (int) m_begin.imag() << "\" y1=\"" << (int) m_begin.real() << 
		"\" x2=\""<< (int) m_end.imag() << "\" y2=\"" << (int) m_end.real() << 
		"\" " << "stroke=\"" << m_color << "\" stroke-width =\"" << stroke_width << "\" />";
	return stream.str();
}
