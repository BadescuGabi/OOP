//
// Created by Gabi on 06.04.2020.
//

#include "Matrice.h"
#include "Complex.h"
#include <iostream>
using namespace std;

Matrice::Matrice() : v(v) {}

Matrice::Matrice(Complex *ob){
    this->v=ob;
}

Matrice::~Matrice() {
this->v=NULL;
}

std::ostream &operator<<(std::ostream &os, const Matrice &matrice) {
    return os;
}

Complex *Matrice::getV() const {
    return v;
}

void Matrice::setV(Complex *v) {
    Matrice::v = v;
}
