#pragma once

#include <string>

class complexnumber {
	public:
		complexnumber(double real = 0, double imaginary = 0);

		double real() const;
		double imag() const;
		bool is_real() const; 
		bool is_imag() const;
		bool is_nearly_equal(const complexnumber &c) const;
		std::string name() const;
		std::string color() const;

		void real(double real);
		void imag(double imag);
		void name(const std::string &name);
		void color(const std::string &color);
		void add (const complexnumber &c); 

		std::string to_string() const;
		std::string to_svg() const;

		static complexnumber add(const complexnumber &c1, const complexnumber &c2);

		static constexpr int radius = 2;
	private:
		double m_real = 0;
		double m_imag = 0;
		std::string m_name = "";
		std::string m_color = "red";
};
