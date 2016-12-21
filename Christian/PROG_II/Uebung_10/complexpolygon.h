#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include "complexnumber.h"

class complexpolygon {
	public:
		complexpolygon(const std::initializer_list<complexnumber> &in);
		complexpolygon(const complexpolygon &c);

		std::string to_svg() const;
		std::string color() const;
		size_t size() const;
		const std::vector<complexnumber> &points() const;

		void color(const std::string &color);
		complexpolygon &operator+=(const complexpolygon& rhs); 
		complexpolygon &operator+=(const complexnumber& rhs);  

		static constexpr int stroke_width = 2;
	private:
		std::vector<complexnumber> m_points;
		std::string m_color = "blue";
};

std::ostream& operator<<(std::ostream& out, const complexpolygon& polygon);
complexpolygon &operator<<(complexpolygon& out, const complexnumber& point); 
complexpolygon operator+(const complexpolygon& cp1, const complexpolygon& cp2); 
