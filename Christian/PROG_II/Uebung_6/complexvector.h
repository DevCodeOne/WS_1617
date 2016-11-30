#pragma once

#include <string>

#include "complexnumber.h" 

class complexvector {
	public :
		complexvector(complexnumber begin, complexnumber end); 
		~complexvector();

		complexnumber begin() const;
		complexnumber end() const;
		std::string color() const;
		std::string to_svg() const;

		void color(const std::string &color);

		static constexpr int stroke_width = 2;
		
	private :
		complexnumber m_begin;
		complexnumber m_end;

		std::string m_color = "red";
};
