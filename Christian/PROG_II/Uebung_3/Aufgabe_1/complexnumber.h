#pragma once

bool smaller_than_eps(double val); 

/* Testen der Funktionen */

class complexnumber {
	public:
		complexnumber() = default;
		complexnumber(double real, double imaginary = 0);
		double real() const;
		double imag() const;
		bool is_real() const; 
		bool is_imag() const;
		void real(double real);
		void imag(double imag);
		void add (complexnumber c); 
		static complexnumber add(complexnumber c1, complexnumber c2);
	private:
		double m_real = 0;
		double m_imag = 0;
};
