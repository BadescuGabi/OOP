//
// Created by Gabi on 04.04.2020.
//

#ifndef UNTITLED2_COMPLEX_H
#define UNTITLED2_COMPLEX_H


#include <ostream>

class Complex {
    float a;
    float b;

public:

    Complex();

    Complex(float a, float b);

    Complex(const Complex &x);

    virtual ~Complex();

    float getA() const;

    float getB() const;

    void setA(float a);

    void setB(float b);

    friend std::istream &operator>>(std::istream &in,  Complex &complex);

    friend std::ostream &operator<<(std::ostream &os, const Complex &complex);

    Complex operator+(Complex &ob);

    Complex operator-(Complex &ob);

    Complex operator*(Complex &ob);

    Complex &operator=(const Complex &ob);
};

#endif //UNTITLED2_COMPLEX_H
