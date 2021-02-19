//
// Created by Gabi on 20.04.2020.
//

#ifndef UNTITLED2_MATRICE_OARECARE_H
#define UNTITLED2_MATRICE_OARECARE_H

#include <iostream>
#include "Matrice.h"
#include <vector>
#include "Complex.h"
using namespace std;
class matrice_oarecare: public Matrice {
    int lin;
    int col;
    matrice_oarecare *vf=NULL;
    matrice_oarecare *next=NULL;
public:

    matrice_oarecare(int,int,int,int);

    matrice_oarecare();

    matrice_oarecare(const matrice_oarecare&ob);

    matrice_oarecare(int lin, int col);

    matrice_oarecare(int a,int b,int c);



    void triunghiular();

    void push(matrice_oarecare *&vf,int lin,int col);

    virtual ~matrice_oarecare();

    matrice_oarecare &operator=(const matrice_oarecare &ob);

    friend ostream &operator<<(ostream &os,  matrice_oarecare &oarecare);

    friend  istream &operator>>(istream &in, matrice_oarecare &oarecare);
};




#endif //UNTITLED2_MATRICE_OARECARE_H
