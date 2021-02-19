//
// Created by Gabi on 22.04.2020.
//

#include "matrice_patratica.h"
#include "Matrice.h"
#include <iostream>

using namespace std;




matrice_patratica::matrice_patratica(int a,int b,int c,int d) : Matrice(v) {
    this->v = new Complex(dim.first, dim.second);
}

matrice_patratica::matrice_patratica(): Matrice(v){

}

matrice_patratica::matrice_patratica(int a, int b): Matrice(v){
    this->v=new Complex;
}

matrice_patratica::matrice_patratica(const matrice_patratica &ob) : dim{ob.dim}, next{ob.next}, Matrice(v) {}

matrice_patratica::matrice_patratica(int dim) : Matrice(v) {
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            push(vf, i, j);
}

void matrice_patratica::triunghiular() {
    matrice_patratica *nou=new matrice_patratica(0,0) ;
    nou->next=this->vf;
    int ok1 = 0, ok2 = 0;
    while (nou->next != NULL) {
        if (nou->next->dim.second < nou->next->dim.first and nou->next->v->getA() != 0 and nou->next->v->getB() != 0)
            ok1 = 1;
        if (nou->next->dim.second > nou->next->dim.first and nou->next->v->getA() != 0 and nou->next->v->getB() != 0)
            ok2 = 1;
        nou->next = nou->next->next;
    }
    if (!ok1) {
        cout << "Matricea este triunghiular inferioara";
        cout << endl;
    }
    if (!ok2) {
        cout << "Matricea este triunghiular superioara";
        cout << endl;
    }
    if (!ok1 and !ok2) {
        cout << "=>Matricea este diagonala"<<endl;
    }
}

void matrice_patratica::push(matrice_patratica *&vf, int i, int j) {
    matrice_patratica *patratica = new matrice_patratica(0,0,0,0);
    patratica->dim.first = i;
    patratica->dim.second = j;
    patratica->next = vf;
    vf = patratica;
    this->next = vf;

}

matrice_patratica::~matrice_patratica() {
    dim.first = 0;
    dim.second = 0;
    while (matrice_patratica::vf->next != NULL) {
        next = matrice_patratica::vf->next;
        free(matrice_patratica::vf);
        matrice_patratica::vf = next;
    }
    next = NULL;
    vf = NULL;
}

matrice_patratica &matrice_patratica::operator=(const matrice_patratica &ob) {
    if (this != &ob) {
        dim.first = ob.dim.first;
        dim.second = ob.dim.second;
        next = ob.next;
        vf = ob.vf;
        v = ob.v;
    }
}

ostream &operator<<(ostream &os, matrice_patratica &patratica) {
    int var = patratica.dim.first;
    patratica.determinant(var,patratica);
    while (patratica.next != NULL) {
        os << "pozitia pe care ne aflam: [" << patratica.next->dim.first << "] " << "[" << patratica.next->dim.second
           << "]";
        cout << endl;
        os << "valoarea ei este: " << patratica.next->v->getA() << " " << patratica.next->v->getB()<<"i";
        cout << endl;
        cout << endl;
        patratica.next = patratica.next->next;
    }

}

istream &operator>>(istream &in, matrice_patratica &patratica) {
    cout<<"Se citeste gradul";
    in >> patratica.dim.first;
    patratica.dim.second=patratica.dim.first;
    for (int i = 0; i < patratica.dim.first; i++)
        for (int j = 0; j < patratica.dim.second; j++)
            patratica.push(patratica.vf, i, j);
}

void matrice_patratica::determinant(int var,matrice_patratica &patratica) {
    if (var == 1)
        cout << this->next->v;
    if (var == 2) {
        int i = 0;
        pair<float, float> s, d, rez;
        s.first = 0, s.second = 0;
        d.first = 0, d.second = 0;
        matrice_patratica *noua=new matrice_patratica(0,0) ;
        noua->next=this->vf;
        while (noua->next != NULL) {
            if(i==0){
                s.first=noua->next->v->getA();
                s.second=noua->next->v->getB();
            }
            if(i==1){
                d.first=noua->next->v->getA();
                d.second=noua->next->v->getB();
            }
            if (i==3 and s.first!=0 and s.second!=0 ) {
                int copie_first=s.first;
                s.first = s.first * noua->next->v->getA() - s.second * noua->next->v->getB();
                s.second = copie_first * noua->next->v->getB() + s.second * noua->next->v->getA();
            } if(i==2  and d.first!=0 and d.second!=0 ){
                int copie_first=d.first;
                d.first = d.first * noua->next->v->getA() - d.second * noua->next->v->getB();
                d.second = copie_first * noua->next->v->getB() + d.second * noua->next->v->getA();
            }
            i++;
            noua->next = noua->next->next;
        }
        rez.first = s.first - d.first;
        rez.second = s.second - d.second;
        cout << "Determinantul matricei are partea reala: " << rez.first << " si cea imaginara: " << rez.second<<endl;
    }
    if(var==3){
        pair<float, float> s1,s2,s3, d1,d2,d3, rez;
        s1.first = 0, s1.second = 0,s2.first=0,s2.second=0,s3.first=0,s3.second=0;
        d1.first = 0, d1.second = 0,d2.first=0,d2.second=0,d3.first=0,d3.first=0;
        matrice_patratica *noua=new matrice_patratica(0,0) ;
        noua->next=vf;
        while (noua->next != NULL){
            if(noua->next->dim.first==2 and noua->next->dim.second==2 ){
                s1.first=noua->next->v->getA();
                s1.second=noua->next->v->getB();
                d3.first=noua->next->v->getA();
                d3.second=noua->next->v->getB();
            }
            if(noua->next->dim.first==2 and noua->next->dim.second==1 ){
                s2.first=noua->next->v->getA();
                s2.second=noua->next->v->getB();
                d2.first=noua->next->v->getA();
                d2.second=noua->next->v->getB();
            }
            if(noua->next->dim.first==2 and noua->next->dim.second==0 ){
                s3.first=noua->next->v->getA();
                s3.second=noua->next->v->getB();
                d1.first=noua->next->v->getA();
                d1.second=noua->next->v->getB();
            }
            if(noua->next->dim.first==1 and noua->next->dim.second==2 ){
                int copie_first=s3.first;
                s3.first = s3.first * noua->next->v->getA() - s3.second * noua->next->v->getB();
                s3.second = copie_first * noua->next->v->getB() + s3.second * noua->next->v->getA();
                int copie_first2=d2.first;
                d2.first = d2.first * noua->next->v->getA() - d2.second * noua->next->v->getB();
                d2.second = copie_first2 * noua->next->v->getB() + d2.second * noua->next->v->getA();
            }
            if(noua->next->dim.first==1 and noua->next->dim.second==1 ){
                int copie_first=s1.first;
                s1.first = s1.first * noua->next->v->getA() - s1.second * noua->next->v->getB();
                s1.second = copie_first * noua->next->v->getB() + s1.second * noua->next->v->getA();
                int copie_first2=d1.first;
                d1.first = d1.first * noua->next->v->getA() - d1.second * noua->next->v->getB();
                d1.second = copie_first2 * noua->next->v->getB() + d1.second * noua->next->v->getA();
            }
            if(noua->next->dim.first==1 and noua->next->dim.second==0 ){
                int copie_first=s2.first;
                s2.first = s2.first * noua->next->v->getA() - s2.second * noua->next->v->getB();
                s2.second = copie_first * noua->next->v->getB() + s2.second * noua->next->v->getA();
                int copie_first2=d3.first;
                d3.first = d3.first * noua->next->v->getA() - d3.second * noua->next->v->getB();
                d3.second = copie_first2 * noua->next->v->getB() + d3.second * noua->next->v->getA();
            }
            if(noua->next->dim.first==0 and noua->next->dim.second==2 ){
                int copie_first=s2.first;
                s2.first = s2.first * noua->next->v->getA() - s2.second * noua->next->v->getB();
                s2.second = copie_first * noua->next->v->getB() + s2.second * noua->next->v->getA();
                int copie_first2=d1.first;
                d1.first = d1.first * noua->next->v->getA() - d1.second * noua->next->v->getB();
                d1.second = copie_first2 * noua->next->v->getB() + d1.second * noua->next->v->getA();
            }
            if(noua->next->dim.first==0 and noua->next->dim.second==1 ){
                int copie_first=s3.first;
                s3.first = s3.first * noua->next->v->getA() - s3.second * noua->next->v->getB();
                s3.second = copie_first * noua->next->v->getB() + s3.second * noua->next->v->getA();
                int copie_first2=d3.first;
                d3.first = d3.first * noua->next->v->getA() - d3.second * noua->next->v->getB();
                d3.second = copie_first2 * noua->next->v->getB() + d3.second * noua->next->v->getA();
            }
            if(noua->next->dim.first==0 and noua->next->dim.second==0 ){
                int copie_first=s1.first;
                s1.first = s1.first * noua->next->v->getA() - s1.second * noua->next->v->getB();
                s1.second = copie_first * noua->next->v->getB() + s1.second * noua->next->v->getA();
                int copie_first2=d2.first;
                d2.first = d2.first * noua->next->v->getA() - d2.second * noua->next->v->getB();
                d2.second = copie_first2 * noua->next->v->getB() + d2.second * noua->next->v->getA();
            }
            noua->next = noua->next->next;
        }
        rez.first=s1.first+s2.first+s3.first-d1.first-d2.first-d3.first;
        rez.second=s1.second+s2.second+s3.second-d1.second-d2.second-d3.second;
        cout << "Determinantul matricei are partea reala: " << rez.first << " si cea imaginara: " << rez.second<<endl;
    }
    if(var>3)
        cout<<"Fostul laborant mi-a zis sa nu ma complic cu matrice mai mare de ordin 3!!"<<endl;
}
