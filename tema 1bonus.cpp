#include<iostream>
#include <vector>
//Badescu George-Gabriel
using namespace std;

class Produs {
    string unit;
    int pret;
    string nume;
    string data;
    int cantitate;
public:
    int getCantitate() const;

    void setPret(int pret);

public:
    const string &getUnit() const;

    int getPret() const;

    const string &getNume() const;

public:
    const string &getData() const;

public:
    Produs();

    Produs(const Produs &);

    friend istream &operator>>(istream &in, Produs &produs);

    friend ostream &operator<<(ostream &os, const Produs &produs);

    Produs &operator=(const Produs &);

    virtual ~Produs();
};

Produs::Produs() {
    this->pret = 0;
    this->unit = "";
    this->data = "";
    this->nume = "";
    this->cantitate = 0;
}

Produs::Produs(const Produs &prod) {
    if (this != &prod) {
        unit = prod.unit;
        pret = prod.pret;
        nume = prod.nume;
        data = prod.data;
        cantitate = prod.cantitate;
    }
}

Produs::~Produs() {

}

istream &operator>>(istream &in, Produs &produs) {
    cout << "Introduceti numele produsului: ";
    in >> produs.nume;
    cout << "Introduceti data in formatul dd-mm-yyyy";
    in >> produs.data;
    cout << "Introduceti pretul ";
    in >> produs.pret;
    cout << "Introduceti unitatea de masura(kg/litru/bucata)";
    in >> produs.unit;
    cout << "Introduceti cantitatea";
    in >> produs.cantitate;
    cout << '\n';
}

ostream &operator<<(ostream &os, const Produs &produs) {
    os << "unit: " << produs.unit << " pret: " << produs.pret << " nume: " << produs.nume << " data: " << produs.data
       << "cantitate: " << produs.cantitate;
    return os;
}

Produs &Produs::operator=(const Produs &prod) {
    if (this != &prod) {
        unit = prod.unit;
        pret = prod.pret;
        nume = prod.nume;
        data = prod.data;
    }
    return *this;
}

const string &Produs::getData() const {
    return data;
}

const string &Produs::getUnit() const {
    return unit;
}

int Produs::getPret() const {
    return pret;
}

const string &Produs::getNume() const {
    return nume;
}

int Produs::getCantitate() const {
    return cantitate;
}

void Produs::setPret(int pret) {
    Produs::pret = pret;
}


class Magazin {
    vector<Produs> vec;
    int nr_produse;
    Produs a;
    static int nr;
public:
    int getNumarMagazin() const;

private:
    int numar_magazin;
public:
    Magazin() {
        vec.clear();
        nr_produse = 0;
    }

    Magazin(const Magazin &m);

    int getNrProduse() const {
        return nr_produse;
    }

    void modif_pret();

    void nume(string num);

    void verif_data(string);

    virtual ~Magazin() {
    int ok=1;
    }

    Magazin &operator=(const Magazin &);

    friend istream &operator>>(istream &in, Magazin &magazin) {
        nr++;
        magazin.numar_magazin = nr;
        cout << "cate produse doriti sa contina magazinul?";
        in >> magazin.nr_produse;
        cout << "Introduceti produsele";
        for (int i = 0; i < magazin.nr_produse; i++) {
            cout << "Produsul " << i + 1 << ": " << "\n";
            cin >> magazin.a;
            magazin.vec.push_back(magazin.a);
        }
        return in;
    }

    friend ostream &operator<<(ostream &os, const Magazin &magazin) {
        for (auto it = magazin.vec.begin(); it != magazin.vec.end(); it++) {
            cout << "\n" << "Pe data de ";
            cout << it->getData() << " ";
            os << "magazinul primeste " << it->getCantitate() << " de";
            os << " " << it->getUnit();
            os << " " << it->getNume();
            os << " la pretul de " << it->getPret() << " lei";
        }
        return os;
    }
};

int Magazin::nr = 0;

Magazin &Magazin::operator=(const Magazin &mag) {
    if (this != &mag) {
        nr_produse = mag.nr_produse;
        a = mag.a;
        vec = mag.vec;
        numar_magazin=mag.numar_magazin;
    }
    *this;
}

void Magazin::nume(string num) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (it->getNume() == num)
            vec.erase(it);
    }
}

Magazin::Magazin(const Magazin &mag) {
    if (this != &mag) {
        nr_produse = mag.nr_produse;
        a = mag.a;
        vec = mag.vec;
        numar_magazin=mag.numar_magazin;
    }
}

void Magazin::verif_data(string dat) {
    for (auto it = vec.begin(); it != vec.end(); it++)
        if (it->getData() == dat) {
            cout << "Magazinul de care apartine este:" << getNumarMagazin();
        }
}

void Magazin::modif_pret() {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << "doriti sa modificatia pretul produsului?";
        string op;
        cin>>op;
        if (op == "da") {
            cout << "introduceti pretul";
            int pr;
            cin >> pr;
            it->setPret(pr);
        }
    }
}

int Magazin::getNumarMagazin() const {
    return numar_magazin;
}

void menu() {
    cout << "Introduceti optiunea";
    Magazin mag;
    vector<Magazin> lant;
    string rev = "da";
    while (rev == "da") {
        int optiune;
        cin >> optiune;
        if (optiune == 1) {
            cin >> mag;
            lant.push_back(mag);
        }
        if (optiune == 2) {
            for (auto it = lant.begin(); it != lant.end(); it++) {
                cout << *it;
            }
        }
        if (optiune == 3) {
            string data_cautare;
            cin >> data_cautare;
            for (auto it = lant.begin(); it != lant.end(); it++) {
                it->verif_data(data_cautare);
            }
        }
        if (optiune == 4) {
            string prod;
            cin >> prod;
            for (auto it = lant.begin(); it != lant.end(); it++) {
                string op;
                cout << "Doriti sa stergeti un prod?";
                cin >> op;
                if (op == "da")
                    it->nume(prod);
            }
        }
        if (optiune == 5) {
            for (auto it = lant.begin(); it != lant.end(); it++) {
                string op;
                cout << "Doriti sa modificati pretul unui produs";
                cin >> op;
                if (op == "da")
                    it->modif_pret();
            }
        }
        if (optiune == 6) {
            int max = 0;
            Magazin mg;
            for (auto it = lant.begin(); it != lant.end(); it++) {
                if (max < it->getNrProduse()) {
                    max = it->getNrProduse();
                    mg = *it;
                }
            }
            cout << "\n" << "magazinul cu cele mai multe produse este"<<mg;
        }
        cout << "\n" << "doriti sa reveniti la meniu";
        cin >> rev;
    }
}

int main() {
    menu();
}