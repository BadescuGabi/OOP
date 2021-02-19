#include<iostream>
#include <vector>
#include <iterator>
#include <cstring>
#include <cstdlib>
#include <typeinfo>
//Badescu George-Gabriel , grupa 141
//flag pentru auto: have g++ follow the c++11 ISO C++ language standard[std=c++11]
//versiune codeblocks 13.12
using namespace std;


class Zbor {
protected:
    static int index;
    string destinatie;
    string data;
    string ora;
    string durata;
    int nr;
public:
    Zbor();

    static int getIndex();

    Zbor(const string &destinatie, const string &data, const string &ora, const string &durata);

    Zbor(const Zbor &);

    virtual ~Zbor();

    const string &getDestinatie() const;

    virtual void citire(istream &in);

    virtual void afisare(ostream &os) const;

    friend std::istream &operator>>(std::istream &in, Zbor &Zbor);

    friend std::ostream &operator<<(std::ostream &os, const Zbor &Zbor);

    Zbor &operator=(const Zbor &Zbor);
};

int Zbor::index = 0;

Zbor::Zbor(const string &destinatie, const string &data, const string &ora, const string &durata) : destinatie(
        destinatie), data(data), ora(ora), durata(durata) {
    index++;
    nr = index;
}

Zbor::Zbor() {
    this->destinatie = "";
    this->data = "";
    this->ora = "";
    this->durata = "";
    index++;
    nr = index;
}

Zbor::Zbor(const Zbor &Zbor) : destinatie(Zbor.destinatie), data(Zbor.data), ora(Zbor.ora), durata(Zbor.durata),
                               nr(Zbor.nr) {}

Zbor::~Zbor() {}

std::istream &operator>>(std::istream &in, Zbor &Zbor) {
    Zbor.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &os, const Zbor &Zbor) {
    Zbor.afisare(os);
    return os;
}

Zbor &Zbor::operator=(const Zbor &Zbor) {
    if (this != &Zbor) {
        durata = Zbor.durata;
        destinatie = Zbor.destinatie;
        data = Zbor.data;
        ora = Zbor.ora;
        nr = Zbor.nr;
    }
    return *this;
}

void Zbor::citire(istream &in) {
    cout << "destinatie zbor: ";
    in >> destinatie;
    cout << "data zbor: ";
    in >> data;
    cout << "ora zbor: ";
    in >> ora;
    cout << "durata zbor: ";
    in >> durata;
}

void Zbor::afisare(ostream &os) const {
    os << "\n" << "zborul cu numarul " << nr << "pleaca in data de " << data << " la ora " << ora
       << " cu destinatia " << destinatie << " si va dura " << durata;
}

const string &Zbor::getDestinatie() const {
    return destinatie;
}

int Zbor::getIndex() {
    return index;
}

class Escala : public Zbor {
protected:
    string escale;
    int pret;
public:
    Escala();

    Escala(const string &escale, int pret);

    Escala(const Escala &);

    ~Escala();

    const string &getEscale() const;

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const Escala &Escala);

    friend istream &operator>>(istream &in, Escala &Escala);

    Escala &operator=(const Escala &);
};

Escala::Escala(const string &escale, int pret) : Zbor(), escale(escale), pret(pret) {}

Escala::Escala() : Zbor() {
    this->escale = "";
    this->pret = 0;
}

Escala::Escala(const Escala &Escala) : Zbor(Escala), escale(Escala.escale), pret(Escala.pret) {}

Escala::~Escala() {

}


istream &operator>>(istream &in, Escala &Escala) {
    Escala.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const Escala &Escala) {
    Escala.afisare(os);
    return os;
}

Escala &Escala::operator=(const Escala &Escala) {
    Zbor::operator=(Escala);
    if (this != &Escala) {
        pret = Escala.pret;
        escale = Escala.escale;
    }
    return *this;
}

void Escala::citire(istream &in) {
    Zbor::citire(in);
    cout << "\n" << "escale: ";
    cin.get();
    getline(in, escale);
    cout << "pret: ";
    in >> pret;
}

void Escala::afisare(ostream &os) const {
    Zbor::afisare(os);
    cout << "\n" << "Zborul are escala/le la: " << escale << "iar pretul sau este de " << pret;
}

const string &Escala::getEscale() const {
    return escale;
}


class Fara_escala : public Zbor {
protected:
    int greutate_bag;
    int pret_kg;
public:
    Fara_escala();

    Fara_escala(int greutateBag, int pretKg);

    Fara_escala(const Fara_escala &);

    ~Fara_escala();

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const Fara_escala &Fara_escala);

    friend istream &operator>>(istream &in, Fara_escala &Fara_escala);

    Fara_escala &operator=(const Fara_escala &);
};

Fara_escala::Fara_escala(int greutateBag, int pretKg) : Zbor(), greutate_bag(greutateBag), pret_kg(pretKg) {}

Fara_escala::Fara_escala() : Zbor(), pret_kg(pret_kg), greutate_bag(greutate_bag) {}

Fara_escala::Fara_escala(const Fara_escala &Fara_escala) : Zbor(Fara_escala), pret_kg(Fara_escala.pret_kg),
                                                           greutate_bag(Fara_escala.greutate_bag) {}

Fara_escala::~Fara_escala() {

}

istream &operator>>(istream &in, Fara_escala &Fara_escala) {
    Fara_escala.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const Fara_escala &Fara_escala) {
    Fara_escala.afisare(os);
    return os;
}

Fara_escala &Fara_escala::operator=(const Fara_escala &Fara_escala) {
    Zbor::operator=(Fara_escala);
    if (this != &Fara_escala) {
        pret_kg = Fara_escala.pret_kg;
        greutate_bag = Fara_escala.greutate_bag;
    }
    return *this;
}

void Fara_escala::citire(istream &in) {
    Zbor::citire(in);
    cout << "\n" << "greutate bagaj: ";
    in >> greutate_bag;
    cout << "pret per kg: ";
    in >> pret_kg;
}

void Fara_escala::afisare(ostream &os) const {
    Zbor::afisare(os);
    os << '\n' << "greutatea bagajului este " << greutate_bag << " iar pretul pe kilogram " << pret_kg;
}

class Charter : public Zbor {
protected:
    string op_tur;
    int dif;
public:
    Charter();

    //ala cu parametri faci automat

    Charter(const Charter &);

    Charter(const string &opTur, int dif);

    ~Charter();

    void citire(istream &in);

    void afisare(ostream &os) const;

    friend ostream &operator<<(ostream &os, const Charter &Charter);

    friend istream &operator>>(istream &in, Charter &Charter);

    Charter &operator=(const Charter &);
};

Charter::Charter(const string &opTur, int dif) : Zbor(), op_tur(opTur), dif(dif) {}

Charter::Charter() : Zbor() {
    this->op_tur = "";
    this->dif = 0;
}

Charter::Charter(const Charter &Charter) : Zbor(Charter), op_tur(Charter.op_tur), dif(Charter.dif) {}

Charter::~Charter() {

}

istream &operator>>(istream &in, Charter &Charter) {
    Charter.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const Charter &Charter) {
    Charter.afisare(os);
    return os;
}

Charter &Charter::operator=(const Charter &Charter) {
    Zbor::operator=(Charter);
    if (this != &Charter) {
        op_tur = Charter.op_tur;
        dif = Charter.dif;
    }
    return *this;
}

void Charter::citire(istream &in) {
    Zbor::citire(in);
    cout << "\n" << "operatorul de turism este: ";
    cin.get();
    getline(in, op_tur);
    cout << "diferenta: ";
    in >> dif;
}

void Charter::afisare(ostream &os) const {
    Zbor::afisare(os);
    cout << "\n" << "operatorul de turism care oferă pachetul cu servicii la sol este " << op_tur
         << " iar diferenta este: " << dif;
}


class Companie {
protected:
    string nume;
    int an_infiint;
    string cod;
    string conexiuni;
public:
    Companie();

    //genereaza l automat pe ala cu parametri

    Companie(const Companie &);

    Companie(const string &nume, int anInfiint, const string &cod, const string &conexiuni);

    virtual ~Companie();

    virtual void citire(istream &in);

    virtual void afisare(ostream &os) const;

    friend std::istream &operator>>(std::istream &in, Companie &Companie);

    friend std::ostream &operator<<(std::ostream &os, const Companie &Companie);

    Companie &operator=(const Companie &Companie);

    virtual void adaug_zbor() = 0;
};

Companie::Companie(const string &nume, int anInfiint, const string &cod, const string &conexiuni)
        : nume(nume),
          an_infiint(
                  anInfiint),
          cod(cod), conexiuni(conexiuni) {}

Companie::Companie() {
    this->nume = "";
    this->cod = "";
    this->an_infiint = 0;
    this->conexiuni = "";
}

Companie::Companie(const Companie &Companie) : nume(Companie.nume), cod(Companie.cod), conexiuni(Companie.conexiuni),
                                               an_infiint(Companie.an_infiint) {}

Companie::~Companie() {}

std::istream &operator>>(std::istream &in, Companie &Companie) {
    Companie.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &os, const Companie &Companie) {
    Companie.afisare(os);
    return os;
}

Companie &Companie::operator=(const Companie &Companie) {
    if (this != &Companie) {
        nume = Companie.nume;
        cod = Companie.cod;
        an_infiint = Companie.an_infiint;
        conexiuni = Companie.conexiuni;

    }
    return *this;
}

void Companie::citire(istream &in) {
    cout << "Numle companiei: ";
    in >> nume;
    cout << "Anul infiintari: ";
    in >> an_infiint;
    cout << "Destinatiile: ";
    cin.get();
    getline(in, conexiuni);
    cout << "cod ICAO/IATA: ";
    in >> cod;

}

void Companie::afisare(ostream &os) const {
    os << nume << " a fost infiintata in anul " << an_infiint << " are sediul la Bucuresti" << ", codul este " << cod
       << " si are conexiuni in " << conexiuni;
}

class Lowcost : public Companie {
protected:
    vector<Zbor *> zb;
    int cost_sup;
public:
    Lowcost();

    Lowcost(const Lowcost &);

    ~Lowcost();

    void caut_loc(string loc);

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const Lowcost &Lowcost);

    friend istream &operator>>(istream &in, Lowcost &Lowcost);

    Lowcost &operator=(const Lowcost &);

    void adaug_zbor();
};

Lowcost::Lowcost() : Companie(), cost_sup(cost_sup) {}

Lowcost::Lowcost(const Lowcost &Lowcost) : Companie(Lowcost), zb(Lowcost.zb), cost_sup(Lowcost.cost_sup) {}

Lowcost::~Lowcost() {

}

istream &operator>>(istream &in, Lowcost &Lowcost) {
    Lowcost.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const Lowcost &Lowcost) {
    Lowcost.afisare(os);
    return os;
}

Lowcost &Lowcost::operator=(const Lowcost &Lowcost) {
    Companie::operator=(Lowcost);
    if (this != &Lowcost) {
        zb = Lowcost.zb;
        cost_sup = Lowcost.cost_sup;
    }
    return *this;
}

void Lowcost::citire(istream &in) {
    Companie::citire(in);
    cout << "\n";
    cout << "cost suplim ";
    in >> cost_sup;
}

void Lowcost::afisare(ostream &os) const {
    Companie::afisare(os);
    os << "\n" << "costul suplimentar adaugat de companie pentru bagajul de cala per kg este: " << cost_sup;
    for (auto it = zb.begin(); it != zb.end(); it++) {
        cout << **it << "\n";
    }
}

void Lowcost::adaug_zbor() {
    cout << "Ce tip de zbor doriti sa adaugati?(charter/fara_escala";
    string opt;
    cin.get();
    getline(cin, opt);
    if (opt == "fara escala") {
        Zbor *p = new Fara_escala;
        cin >> *p;
        zb.push_back(p);
    }
    if (opt == "charter") {
        Zbor *p = new Charter;
        cin >> *p;
        zb.push_back(p);
    }
}

void Lowcost::caut_loc(string loc) {
for(auto it=zb.begin();it!=zb.end();it++){
    if(static_cast<Zbor*>(*it)){

    }
}
}

class De_linie : public Companie {
protected://depinde
    vector<Zbor *> zboruri;
public:
    De_linie();

    De_linie(const De_linie &);

    ~De_linie();

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const De_linie &De_linie);

    friend istream &operator>>(istream &in, De_linie &De_linie);

    De_linie &operator=(const De_linie &);

    void adaug_zbor();
};

De_linie::De_linie() : Companie() {
    zboruri.clear();
}

De_linie::De_linie(const De_linie &De_linie) : Companie(De_linie), zboruri(De_linie.zboruri) {}

De_linie::~De_linie() {

}

istream &operator>>(istream &in, De_linie &De_linie) {
    De_linie.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const De_linie &De_linie) {
    De_linie.afisare(os);
    return os;
}

De_linie &De_linie::operator=(const De_linie &De_linie) {
    Companie::operator=(De_linie);
    if (this != &De_linie) {

    }
    return *this;
}

void De_linie::citire(istream &in) {
    Companie::citire(in);
}

void De_linie::afisare(ostream &os) const {
    Companie::afisare(os);
    for (auto it = zboruri.begin(); it != zboruri.end(); it++) {
        cout << **it << "\n";
    }
}

void De_linie::adaug_zbor() {
    cout << "Ce tip de zbor doriti sa adaugati?(escala/charter/fara escala";
    string opt;
    cin.get();
    getline(cin, opt);
    if (opt == "escala") {
        Zbor *p = new Escala;
        cin >> *p;
        zboruri.push_back(p);
    }
    if (opt == "fara escala") {
        Zbor *p = new Fara_escala;
        cin >> *p;
        zboruri.push_back(p);
    }
    if (opt == "charter") {
        Zbor *p = new Charter;
        cin >> *p;
        zboruri.push_back(p);
    }
}


void menu() {
    vector<Companie *> vec;
    string opt4 = "da";
    while (opt4 == "da") {
        string opt;
        cout << "1.adaug companie" << "\n";
        cout << "2.afis zboruri pe 1 septembrie" << "\n";
        cout << "3.afis zboruri ce duc spre un oras" << "\n";
        cout << "4.estimare pret minim" << "\n";
        cout << "1/2/3/4";
        getline(cin, opt);
        if (opt == "1") {
            cout << "ce companie doriti sa adaugati?(low-cost/linie";
            string opt2;

            getline(cin, opt2);
            if (opt2 == "low-cost") {
                Companie *a = new Lowcost;
                vec.push_back(a);
                cout << "cate zboruri doriti sa adaugati in companie";
                int opt3;
                cin >> opt3;
                for (int i = 0; i < opt3; i++) {
                    vec[vec.size() - 1]->adaug_zbor();
                }
            }
            if (opt2 == "linie") {
                Companie *a = new De_linie;
                vec.push_back(a);
                cout << "cate zboruri doriti sa adaugati in companie";
                int opt3;
                cin >> opt3;
                for (int i = 0; i < opt3; i++) {
                    vec[vec.size() - 1]->adaug_zbor();
                }
            }
        }
        if (opt == "3") {
            string locatie;
            cout << "ce locatie cautati";
            getline(cin, locatie);
            for (auto it = vec.begin(); it != vec.end(); it++) {
                if (dynamic_cast<De_linie *>(*it)) {

                }
                if (dynamic_cast<Lowcost *>(*it)) {

                }
            }
        }
        cout << "doriti sa reveniti la meniu?";
        getline(cin, opt4);
    }
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << **it;
}

int main() {
    menu();
}