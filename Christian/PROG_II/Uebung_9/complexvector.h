#pragma once

#include <string>

#include "complexnumber.h" 

class complexvector {
	public :
		complexvector(const complexnumber &begin, const complexnumber &end); 
		complexvector(const complexvector &v);
		~complexvector();

		complexvector &operator=(const complexvector &v);

		complexnumber begin() const;
		complexnumber end() const;
		std::string color() const;
		std::string to_svg() const;

		void color(const std::string &color);

		static constexpr int stroke_width = 2;
		
	private :
		complexnumber m_begin;
		complexnumber m_end;
		const int m_serialnr;

		std::string m_color = "red";
};
