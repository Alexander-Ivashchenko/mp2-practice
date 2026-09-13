#include "../include/complex.h"
#include <iostream>



Complex::Complex() : re(0.0f), im(0.0f) {
}

Complex::Complex(float re, float im) : re(re), im(im) {
}

Complex::Complex(const Complex& other) : re(other.re), im(other.im) {
}




Complex::~Complex() {
}



Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        re = other.re;
        im = other.im;
    }
    return *this;
}


Complex Complex::operator+(const Complex& o) const {
    return Complex(re + o.re, im + o.im);
}

Complex Complex::operator-(const Complex& o) const {
    return Complex(re - o.re, im - o.im);
}

Complex Complex::operator*(const Complex& o) const {
    return Complex(re * o.re - im * o.im,
        re * o.im + im * o.re);
}

Complex Complex::operator/(const Complex& o) const {
    float denom = o.re * o.re + o.im * o.im;

    
    if (denom == 0.0f) {
        std::cout << "Error: division by zero complex number!\n";
        return Complex(0.0f, 0.0f);
    }

    return Complex((re * o.re + im * o.im) / denom,
        (im * o.re - re * o.im) / denom);
}



Complex& Complex::operator+=(const Complex& o) {
    re += o.re;
    im += o.im;
    return *this;
}



bool Complex::operator==(const Complex& o) const {
    return re == o.re && im == o.im;
}

bool Complex::operator!=(const Complex& o) const {
    return !(*this == o);
}



Complex& Complex::operator++() {
    ++re;
    return *this;
}

Complex Complex::operator++(int) {
    Complex old = *this;
    ++re;
    return old;
}

Complex& Complex::operator--() {
    --re;
    return *this;
}

Complex Complex::operator--(int) {
    Complex old = *this;
    --re;
    return old;
}



std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re;
    if (c.im >= 0)
        os << "+" << c.im << "i";
    else
        os << c.im << "i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.re >> c.im;
    return is;
}