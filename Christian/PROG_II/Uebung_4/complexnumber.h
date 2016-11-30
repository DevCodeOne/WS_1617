#pragma once

#include <string>

class complexnumber {
	public:
		complexnumber(double real = 0, double imaginary = 0);
		double real() const;
		double imag() const;
		std::string name() const;
		bool is_real() const; 
		bool is_imag() const;
		void real(double real);
		void imag(double imag);
		void name(std::string name);
		void add (complexnumber c); 

		std::string to_string();

		static complexnumber add(complexnumber c1, complexnumber c2);
	private:
		double m_real = 0;
		double m_imag = 0;
		std::string m_name = "";
};
