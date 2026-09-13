#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

struct Complex {
	float re;
	float im;


	Complex();
	Complex(float re, float im = 0.0f);
	Complex(const Complex& other);

	~Complex();

	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;

	bool operator==(const Complex&) const;
	bool operator!=(const Complex&) const;

	Complex& operator=(const Complex&);
	Complex& operator+=(const Complex&);

	Complex& operator++();
	Complex  operator++(int);
	Complex& operator--();
	Complex  operator--(int);

	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend std::istream& operator>>(std::istream& is, Complex& c);

};

#endif
