#include "../include/complex.h"
#include <iostream>

int main() {
    Complex a(3.0f, 4.0f);
    Complex b(1.0f, -2.0f);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "a * b = " << a * b << "\n";
    std::cout << "a / b = " << a / b << "\n";
    std::cout << "a == b? " << (a == b) << "\n";
    std::cout << "a != b? " << (a != b) << "\n";

    Complex c = a;
    c += b;
    std::cout << "c = a; c += b -> " << c << "\n";

    std::cout << "++a = " << ++a << "\n";
    std::cout << "b++ = " << b++ << "\n";
    std::cout << "b после b++ = " << b << "\n";

   
    Complex zero(0.0f, 0.0f);
    std::cout << "\nПроверка деления на ноль:\n";
    std::cout << "a / zero = " << a / zero << "\n";

    Complex d;
    std::cout << "Введите re im: ";
    std::cin >> d;
    std::cout << "d = " << d << "\n";

    return 0;
}