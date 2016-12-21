#include <sstream>

#include "complexpolygon.h"

// ändere den Konstruktur noch, sodass ein Polygon nicht mit weniger als 3 "Punkten" 
// initialisiert werden kann
complexpolygon::complexpolygon(const std::initializer_list<complexnumber> &in) 
	: m_points(in) {
}

complexpolygon::complexpolygon(const complexpolygon &c) : m_points(c.m_points) {
}

size_t complexpolygon::size() const {
	return m_points.size();
}

const std::vector<complexnumber> &complexpolygon::points() const {
	return m_points;
}

std::string complexpolygon::to_svg() const {
	std::stringstream stream;
	stream << "<polygon";
	stream << " stroke-width=\"" << complexpolygon::stroke_width << "\" ";
	stream << " stroke=\"" << m_color << "\"";
	stream << " points=\"";

	for (const complexnumber &c : m_points)
		stream << c.real() << "," << c.imag() << " ";

	stream << "\" />";
	return stream.str();
}

complexpolygon &complexpolygon::operator+=(const complexpolygon& rhs) {
	m_points.insert(m_points.end(), rhs.m_points.begin(), rhs.m_points.end());
	return *this;
}

complexpolygon &complexpolygon::operator+=(const complexnumber& rhs) {
	m_points.push_back(rhs);
	return *this;
}

complexpolygon &operator<<(complexpolygon& out, const complexnumber& point) {
	return (out += point);
}

std::ostream& operator<<(std::ostream& out, const complexpolygon& polygon) {
	out << "{ ";
	for (const complexnumber &c : polygon.points()) 
		out << c << " ";

	return (out << "}");
}

complexpolygon operator+(const complexpolygon& cp1, const complexpolygon& cp2) {
	complexpolygon poly = cp1;
	return (poly += cp2);
}
