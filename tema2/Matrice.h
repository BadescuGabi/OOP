//
// Created by Gabi on 06.04.2020.
//

#ifndef UNTITLED2_MATRICE_H
#define UNTITLED2_MATRICE_H


#include <iostream>
#include "Complex.h"

class Matrice {
protected:
    Complex *v;
public:
    Matrice();

    Matrice(Complex *v);

    virtual ~Matrice();

    Complex *getV() const;

    void setV(Complex *v);

    friend std::ostream &operator<<(std::ostream &os, const Matrice &matrice);

    virtual void triunghiular()=0;

};


#endif //UNTITLED2_MATRICE_H
