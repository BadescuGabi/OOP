//
// Created by Gabi on 20.04.2020.
//

#include "matrice_oarecare.h"
#include "Matrice.h"
#include "Complex.h"

matrice_oarecare::matrice_oarecare(int lin, int col) : Matrice(v) {
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            push(vf, i, j);

}

matrice_oarecare::matrice_oarecare(int a, int b,int c): Matrice(v){
    this->v=new Complex;
}

matrice_oarecare::~matrice_oarecare() {
    lin = 0;
    col = 0;
    while (matrice_oarecare::vf->next != NULL) {
        next = matrice_oarecare::vf->next;
        free(matrice_oarecare::vf);
        matrice_oarecare::vf = next;
    }
    next = NULL;
    vf = NULL;
}

void matrice_oarecare::push(matrice_oarecare *&vf, int lin, int col) {
    matrice_oarecare *oarecare = new matrice_oarecare(0,0,0,0);
    oarecare->lin = lin;
    oarecare->col = col;
    oarecare->next = vf;
    vf = oarecare;
    this->next = vf;

}

matrice_oarecare &matrice_oarecare::operator=(const matrice_oarecare &ob) {
    if (this != &ob) {
        lin = ob.lin;
        col = ob.col;
        next = ob.next;
        vf = ob.vf;
        v = ob.v;
    }
}

istream &operator>>(istream &in, matrice_oarecare &oarecare) {
   cout<<"Se citeste linia si dupa coloana";
    in >> oarecare.lin;
    in >> oarecare.col;
    for (int i = 0; i < oarecare.lin; i++)
        for (int j = 0; j < oarecare.col; j++)
            oarecare.push(oarecare.vf, i, j);
        cout<<"gata citirea"<<endl;
}

ostream &operator<<(ostream &os, matrice_oarecare &oarecare) {
    while (oarecare.next != NULL) {
        os << "pozitia pe care ne aflam: [" << oarecare.next->lin << "] " << "[" << oarecare.next->col << "]";
        cout << endl;
        os << "valoarea ei este: " << oarecare.next->v->getA() << " " << oarecare.next->v->getB()<<"i";
        cout << endl;
        cout << endl;
        oarecare.next = oarecare.next->next;
    }
}

void matrice_oarecare::triunghiular() {
    matrice_oarecare *nou = new matrice_oarecare(0,0,0);
    nou->next=this->vf;
    int ok1 = 0, ok2 = 0;
    while (nou->next != NULL) {
        if (nou->next->col < nou->next->lin and nou->next->v->getA()!=0 and nou->next->v->getB()!=0)
                ok1=1;
        if (nou->next->col > nou->next->lin and nou->next->v->getA()!=0 and nou->next->v->getB()!=0)
            ok2=1;
        nou->next=nou->next->next;
    }
    if(!ok1){
        cout<<"Matricea este triunghiular inferioara";
        cout<<endl;}
    if(!ok2){
        cout<<"Matricea este triunghiular superioara";
        cout<<endl;
    }
    if(!ok1 and !ok2){
        cout<<"=>Matricea este diagonala";
    }
}


matrice_oarecare::matrice_oarecare() : Matrice(v) {

}

matrice_oarecare::matrice_oarecare(int a, int b ,int c,int d ) : Matrice(v) {
    try {
       this-> v =  new Complex(lin, col);
    } catch (bad_array_new_length) {
        cerr << "Memorie insuficienta";
        exit(1);
    }}

matrice_oarecare::matrice_oarecare(const matrice_oarecare &ob) : lin{ob.lin}, col{ob.col}, next{ob.next}, Matrice(v) {}
