//
// Created by Gabi on 22.04.2020.
//

#ifndef UNTITLED2_MATRICE_PATRATICA_H
#define UNTITLED2_MATRICE_PATRATICA_H

#include "Complex.h"
#include "Matrice.h"
#include <iostream>
#include <stdint.h>
using namespace std;

class matrice_patratica: public Matrice {
    matrice_patratica *vf=NULL;
    matrice_patratica *next=NULL;
    pair <int,int> dim; //linie,coloana

public:
    matrice_patratica();

    matrice_patratica(int a,int b);

    matrice_patratica(const matrice_patratica &ob);

    matrice_patratica(int dim);

    matrice_patratica(int,int,int,int);

    void triunghiular();

    void determinant(int dim,matrice_patratica &patratica);

    void push(matrice_patratica *&vf, int lin, int col);

    virtual ~matrice_patratica();

    matrice_patratica &operator=(const matrice_patratica &ob);

    friend ostream &operator<<(ostream &os, matrice_patratica &patratica);

    friend istream &operator>>(istream &in, matrice_patratica &patratica);

};

#endif //UNTITLED2_MATRICE_PATRATICA_H
