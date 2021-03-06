#pragma once

#include <string>
#include <iostream>

class complexnumber {
	public:
		complexnumber(double real = 0, double imaginary = 0);
		complexnumber(const complexnumber &c);
		~complexnumber();

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


		complexnumber &operator+=(const complexnumber &right);
		complexnumber &operator-=(const complexnumber &right);
		complexnumber &operator*=(const complexnumber &right);
		complexnumber &operator/=(const complexnumber &right);
		complexnumber &operator=(const complexnumber &right);

		complexnumber operator+() const;
		complexnumber operator-() const;

		std::string to_string() const;
		std::string to_svg() const;

		static complexnumber add(const complexnumber &c1, const complexnumber &c2);

		static constexpr int radius = 2;
	private:
		double m_real = 0;
		double m_imag = 0;
		const int m_serialnr;

		std::string m_name = "";
		std::string m_color = "red";
};

std::ostream &operator<<(std::ostream &os, const complexnumber &c);
complexnumber operator+(const complexnumber &left, const complexnumber &right);
complexnumber operator-(const complexnumber &left, const complexnumber &right);
complexnumber operator*(const complexnumber &left, const complexnumber &right);
complexnumber operator/(const complexnumber &left, const complexnumber &right);
bool operator==(const complexnumber &left, const complexnumber &right);
