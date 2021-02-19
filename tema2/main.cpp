#include<iostream>
#include "Complex.h"
#include "Matrice.h"
#include "matrice_oarecare.h"
#include "matrice_patratica.h"
#include <vector>
#include <typeinfo>

using namespace std;
//TEMA: mmatrice de nr complexe cu structuri inlantuite
//important!!!! la citire se vor citi intai linia si coloana pentru matricea oarecare
// respectiv gradul la cea patratica, apoi se va citi element cu element, un element va contine
//partea reala care va fi citita prima si apoi partea imaginara
int main() {
/*
    Complex C;
    Complex B;
    Complex D;
    Complex A;
   cin >> A;
    cin>>B;
    cin>>C;
    cin>>D;
    cout << A;
    A = B * C + D;
    cout << A;
}*/

/*    matrice_oarecare A[2];
  //citirea a n obiecte
  for(int i=0;i<2;i++)
        cin>>A[i];
A[0].triunghiular();
A[1]=A[0];
cout<<A[1];
}

*/
matrice_patratica A[2];
 //citirea a n obiecte
 for(int i=0;i<2;i++)
     cin>>A[i];
 A[0].triunghiular();
 A[1]=A[0];
 cout<<A[1];
}
