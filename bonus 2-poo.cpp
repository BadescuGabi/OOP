#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <vector>
#include <typeinfo>
#include <iomanip>
#include<math.h>

using namespace std;


class referinte {
public:
    virtual void citire(istream &in) = 0;

    virtual void afisare(ostream &os) const = 0;

    friend ostream &operator<<(ostream &os, const referinte &referinte) {
        referinte.afisare(os);
        return os;
    }

    friend istream &operator>>(istream &in, referinte &referinte) {
        referinte.citire(in);
        return in;
    }
};

class tiparit : public referinte {
    vector<string> n;
    vector<string> p;
    string titlu;
    int an;
    string nume;
public:
    int getAn() const;

public:
    tiparit() {
        this->nume = "";
        this->titlu = "";
        this->an = 0;
    }

    tiparit(const tiparit &t) : n(t.n), p(t.p), nume(t.nume), titlu(t.titlu), an(t.an) {};

    void citire(istream &in);

    void afisare(ostream &os) const;

    bool caut_n(string);

    virtual ~tiparit() {
        n.clear();
        p.clear();
        nume = "";
        titlu = "";
    }

    friend istream &operator>>(istream &os, tiparit &tiparit);

    friend ostream &operator<<(ostream &os, const tiparit &tiparit);

    tiparit &operator=(const tiparit &);
};

bool tiparit::caut_n(string a) {
    for (auto it = n.begin(); it != n.end(); ++it) {
        if (*it == a) {
            return true;
        }
    }
    return false;
}

ostream &operator<<(ostream &os, const tiparit &tiparit) {
    tiparit.afisare(os);
    return os;
}

istream &operator>>(istream &in, tiparit &tiparit) {
    tiparit.citire(in);
    return in;
}

tiparit &tiparit::operator=(const tiparit &t) {
    if (this != &t) {
        n = t.n;
        p = t.p;
        nume = t.nume;
        titlu = t.titlu;
        an = t.an;
    }
    return *this;
}

void tiparit::citire(istream &in) {
    cout << "cati autori sunt?";
    int nu;
    in >> nu;
    for (int i = 0; i < nu; ++i) {
        cout << "nume autor:";
        string s;
        if (i == 0)
            cin.get();
        getline(in, s);
        n.push_back(s);
        cout << "prenume autor";
        getline(in, s);
        p.push_back(s);
    }
    cout << "titlu:";
    in >> titlu;
    cout << "nume";
    cin.get();
    getline(in, nume);
    cout << "an pubicatie";
    in >> an;
}

void tiparit::afisare(ostream &os) const {
    for (int i = 0; i < p.size(); ++i) {
        cout << n[i] << " " << p[i] << ", ";
    }
    cout << ": ";
    os << titlu;
    os << ",\n" << nume << ", " << an;
}

int tiparit::getAn() const {
    return an;
}

class articol : public tiparit {
    int nr;
    string pag;
public:
    articol() : nr(nr), tiparit() {
        this->pag = "";
    }

    articol(const articol &c) : nr(c.nr), pag(c.pag) {}

    virtual ~articol() {
        pag = "";
    }

    void citire(istream &in);

    void afisare(ostream &os) const;

    friend istream &operator>>(istream &in, articol &articol) {
        articol.citire(in);
        return in;
    }

    friend ostream &operator<<(ostream &os, articol &articol) {
        articol.afisare(os);
        return os;
    }

    articol &operator=(const articol &c) {
        if (this != &c) {
            nr = c.nr;
            pag = c.pag;
            tiparit::operator=(c);
        }
        return *this;
    }
};

void articol::afisare(ostream &os) const {
    tiparit::afisare(os);
    cout << ", ";
    os << nr;
    os << ", " << pag;
}

void articol::citire(istream &in) {
    tiparit::citire(in);
    cout << "numarul";
    in >> nr;
    cout << "interval pagini";
    cin.get();
    getline(in, pag);
}

class carte : public tiparit {
    string oras;
public:
    carte() {
        this->oras = "";
    }

    ~carte() {
        oras = "";
    }

    carte(const carte &c) : oras(c.oras) {}

    void citire(istream &in) {
        tiparit::citire(in);
        cout << "nume oras";
        in >> oras;
    }

    void afisare(ostream &os) const {
        tiparit::afisare(os);
        os << " " << oras;
    }

    friend ostream &operator<<(ostream &os, const carte &carte) {
        carte.afisare(os);
        return os;
    }

    friend istream &operator>>(istream &in, carte &carte) {
        carte.citire(in);
        return in;
    }

    carte &operator=(const carte &c) {
        if (this != &c) {
            oras = c.oras;
            tiparit::operator=(c);
        }
        return *this;
    }
};

class web : public referinte {
    string nume;
    string titlu;
    string url;

public:
    web() {
        this->nume = "";
        this->titlu = "";
        this->url = "";
    }

    ~web() = default;

    web(const web &w) : nume(w.nume), titlu(w.titlu), url(w.url) {};

    void citire(istream &in);

    void afisare(ostream &os) const;

    friend istream &operator<<(istream &in, const web &web) {
        return in;
    }

    friend ostream &operator<<(ostream &os, const web &web) {
        return os;
    }

    web &operator=(const web &w) {
        if (this != &w) {
            nume = w.nume;
            titlu = w.titlu;
            url = w.url;
        }
        return *this;
    }
};

void web::citire(istream &in) {
    cout << "nume:";
    in >> nume;
    cout << "titlu:";
    in >> titlu;
    cout << "url:";
    in >> url;
}

void web::afisare(ostream &os) const {
    os << nume;
    os << ": " << titlu << ". " << url;
}

void menu_afis() {
    cout << "0 Iesire";
    cout << "1. A afi?a toate referin?ele de?inute\n";
    cout << "2. A afi?a toate referin?ele în format tipãrit, publicate într-un an dat\n";
    cout
            << " 3. A afi?a toate referin?ele în format tipãrit care au numele (de familie al) unuia dintre autori egal cu un nume dat"
            << "\n";
    cout << "4. A afi?a toate referin?ele în format electronic care au numele proprietarului egal cu un nume dat\n";


}

void menu() {

    vector<referinte *> vec;
    cout<<"cate obiecte doriti sa bagati in referinte?";
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cout<<"ce obiect doriti sa bagati?";
        string opt;
        cin>>opt;
        if(opt=="a"){
            referinte*c=new articol;
            cin>>*c;
            vec.push_back(c);
    }
        if(opt=="c"){
            referinte*c=new carte;
            cin>>*c;
            vec.push_back(c);
        }
        if(opt=="w"){
            referinte*c=new web;
            cin>>*c;
            vec.push_back(c);
        }
   }
    menu_afis();
    int op;
    cin >> op;
    while (op != 0) {
        if (op == 1) {
            for (auto it = vec.begin(); it != vec.end(); it++)
                cout << **it << "\n";
        }
        if (op == 2) {
            cout<<"an cautat:";
            int a;
            cin>>a;
            for (auto it = vec.begin(); it != vec.end(); it++)
                if (tiparit *p=dynamic_cast<tiparit *>(*it)){
                    if(p->getAn()==a)
                        cout<<*p<<'\n';
                }
        }
        if (op == 3) {
            string caut_nume;
            cin.get();
            getline(cin, caut_nume);
            for (auto & it : vec)
                if (tiparit *p = dynamic_cast<tiparit *>(it)) {
                    if (p->caut_n(caut_nume))
                    cout << *p<<'\n';
                }
        }
        if(op==4){
            for (auto & it : vec)
                if (web *p = dynamic_cast<web*>(it)) {
                        cout << *p<<'\n';
        }
    }
cout<<"doriti sa reveniti la meniu?";
        string nume;
        cin>>nume;
        if(nume=="da")
            cin>>op;
        else op=0;
}
}

int main() {
menu();
}