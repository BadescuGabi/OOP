//
// Created by Gabi on 04.04.2020.
//

#include "Complex.h"
#include <iostream>
#include <typeinfo>
using namespace std;

Complex::Complex(float an, float bn){
cout<<"valori pentru elemente din matrice";
    cin.exceptions(istream::failbit); //se asigura ca a si b vor fi de tip float
    cin>>an;
    cin>>bn;

this->a=an;
this->b=bn;
}

Complex::Complex(){
    this->a=1;
    this->b=1;
}


Complex::Complex(const Complex &x) : a{x.a}, b{x.b} {}

Complex::~Complex() {
    this->a = 0;
    this->b = 0;
}

float Complex::getA() const {
    return a;
}

float Complex::getB() const {
    return b;
}

void Complex::setA(float a) {
    Complex::a = a;
}

void Complex::setB(float b) {
    Complex::b = b;
}

std::ostream &operator<<(std::ostream &os, const Complex &complex) {
    os << "a: " << complex.a << " b: " << complex.b;
    return os;
}

Complex Complex::operator+(Complex &ob) {

    ob.a = a + ob.a;
    ob.b = b + ob.b;
    return ob;
}

Complex Complex::operator-(Complex &ob) {

    ob.a = a - ob.a;
    ob.b = b - ob.b;
    return ob;
}

Complex Complex::operator*(Complex &ob) {
    ob.a = a * ob.a - (b * ob.b);
    ob.b = b * ob.a + a * ob.b;
    return ob;
}

istream &operator>>(std::istream &in, Complex &complex) {
    cin.exceptions(istream::failbit);
    cout << "partea reala este: ";
    in >> complex.a;
    cout << "partea imaginara este: ";
    in >> complex.b;
    return in;
}

Complex &Complex::operator=(const Complex &ob) {
    if (this != &ob) {
        a = ob.a;
        b = ob.b;
    }
    return *this;
}
