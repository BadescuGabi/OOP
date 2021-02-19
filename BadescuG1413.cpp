#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
//Badescu George-Gabriel 141
//codeblocks 13.12 gcc compiler
//flag auto
using namespace std;


class elev {
protected:
    int CNP[14];
    string nume;
public:
    elev();

    //genereaza l automat pe ala cu parametri

    elev(const elev &);

    virtual ~elev();

    virtual void citire(istream &in);

    virtual void afisare(ostream &os) const;

    friend std::istream &operator>>(std::istream &in, elev &elev);

    friend std::ostream &operator<<(std::ostream &os, const elev &elev);

    elev &operator=(const elev &elev);

    const int *getCnp() const;

};

const int *elev::getCnp() const {
    return CNP;
}

elev::elev() {
    this->nume = "";
    for (int i = 0; i < 14; i++) {
        this->CNP[i] = 0;
    }
}

elev::elev(const elev &elev) {
    nume = elev.nume;
    for (int i = 0; i < 14; i++) {
        CNP[i] = elev.CNP[i];
    }
}

elev::~elev() {}

std::istream &operator>>(std::istream &in, elev &elev) {
    elev.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &os, const elev &elev) {
    elev.afisare(os);
    return os;
}

elev &elev::operator=(const elev &elev) {
    if (this != &elev) {
        nume = elev.nume;
        for (int i = 0; i < 14; i++) {
            CNP[i] = elev.CNP[i];
        }
    }
    return *this;
}

void elev::citire(istream &in) {
    cout << "nume elev";
    in.get();
    getline(in, nume);
    cout << "introduceti cnp(13 cifre)";
    for (int i = 0; i < 14; i++) {
        in >> CNP[i];
    }
}

void elev::afisare(ostream &os) const {
    os << "nume: " << nume << " CNP: ";
    for (int i = 0; i < 14; i++)
        os << CNP[i];
}


class profesor : public elev {
protected://depinde
    int portof;
public:
    profesor();

    //ala cu parametri faci automat

    profesor(const profesor &);

    ~profesor();

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const profesor &profesor);

    friend istream &operator>>(istream &in, profesor &profesor);

    profesor &operator=(const profesor &);

    int getPortof() const;

    void setPortof(int portof);
};

int profesor::getPortof() const {
    return portof;
}

void profesor::setPortof(int portof) {
    profesor::portof = portof;
}

profesor::profesor() : elev(), portof(portof) {}

profesor::profesor(const profesor &profesor) : elev(profesor), portof(profesor.portof) {}

profesor::~profesor() {

}

istream &operator>>(istream &in, profesor &profesor) {
    profesor.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const profesor &profesor) {
    profesor.afisare(os);
    return os;
}

profesor &profesor::operator=(const profesor &profesor) {
    elev::operator=(profesor);
    if (this != &profesor) {
        portof = profesor.portof;
    }
    return *this;
}

void profesor::citire(istream &in) {
    elev::citire(in);
    cout << "\n" << "numar credite portofoliu personal profesor";
    in >> portof;
}

void profesor::afisare(ostream &os) const {
    elev::afisare(os);
    cout << "numarul de credite portofoliu:";
}


class activitate {
protected:
    string denum;
    string data;
    int nr_zile;
public:
    activitate();

    //genereaza l automat pe ala cu parametri

    activitate(const activitate &);

    virtual ~activitate();

    virtual void citire(istream &in);

    virtual void afisare(ostream &os) const;

    friend std::istream &operator>>(std::istream &in, activitate &activitate);

    friend std::ostream &operator<<(std::ostream &os, const activitate &activitate);

    activitate &operator=(const activitate &activitate);

    int getNrZile() const;

    void setNrZile(int nrZile);
};

activitate::activitate() {
    this->data = "";
    this->nr_zile = 0;
    this->denum = "";
}

int activitate::getNrZile() const {
    return nr_zile;
}

void activitate::setNrZile(int nrZile) {
    nr_zile = nrZile;
}

activitate::activitate(const activitate &activitate) : data(activitate.data), nr_zile(activitate.nr_zile),
                                                       denum(activitate.denum) {}

activitate::~activitate() {}

std::istream &operator>>(std::istream &in, activitate &activitate) {
    activitate.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &os, const activitate &activitate) {
    activitate.afisare(os);
    return os;
}

activitate &activitate::operator=(const activitate &activitate) {
    if (this != &activitate) {
        data = activitate.data;
        nr_zile = activitate.nr_zile;
        denum = activitate.denum;
    }
    return *this;
}

void activitate::citire(istream &in) {
    cout << "data desf activ: ";
    cin.get();
    getline(in, data);
    cout << "nume activ: ";
    in >> denum;
}

void activitate::afisare(ostream &os) const {
    os << "activitatea cu numele de" << denum << " se desfsoara pe: " << data << " si pe durata a " << nr_zile;
}

class concurs_off : public activitate {
protected://depinde
    vector<elev> a;
    int indic;
    vector<int> b;
public:
    concurs_off();

    //ala cu parametri faci automat

    concurs_off(const concurs_off &);

    ~concurs_off();

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const concurs_off &concurs_off);

    friend istream &operator>>(istream &in, concurs_off &concurs_off);

    concurs_off &operator=(const concurs_off &);

    void adaug_elev();

    void afis_prem();

    int verif_cnp()const;
};

concurs_off::concurs_off() : activitate() {
    a.clear();
    this->indic = 0;
    b.clear();
}

concurs_off::concurs_off(const concurs_off &concurs_off) : activitate(concurs_off), a(concurs_off.a),
                                                           indic(concurs_off.indic), b(concurs_off.b) {}

concurs_off::~concurs_off() {

}

istream &operator>>(istream &in, concurs_off &concurs_off) {
    concurs_off.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const concurs_off &concurs_off) {
    concurs_off.afisare(os);
    return os;
}

concurs_off &concurs_off::operator=(const concurs_off &concurs_off) {
    activitate::operator=(concurs_off);
    if (this != &concurs_off) {
        indic = concurs_off.indic;
        a = concurs_off.a;
        b = concurs_off.b;
    }
    return *this;
}

void concurs_off::citire(istream &in) {
    activitate::citire(in);
}

void concurs_off::afisare(ostream &os) const {
    if (verif_cnp() == 1)
        cout << "frauda";
    activitate::afisare(os);
    cout << " sunt " << indic << "participanti";
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
}

void concurs_off::adaug_elev() {
    elev el;
    cin >> el;
    a.push_back(el);
    indic++;
    cout << "punctajul sau: ";
    int pct;
    cin >> pct;
    b.push_back(pct);
}

void concurs_off::afis_prem() {
    vector<int> copie;
    copie = b;
    sort(copie.begin(), copie.end());
    int ok = 0;
    for (auto j = copie.end(); j >= copie.begin(); j--) {
        if (ok == 4) {
            break;
        }
        for (int i = 0; i < b.size(); i++) {
            if (*j == b[i]) {
                cout << a[i];
                break;
            }
        }
        ok++;
    }
    copie.clear();
}

int concurs_off::verif_cnp() const{
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i].getCnp() == a[j].getCnp()) {
                cout << "frauda";
                return 1;
            }
        }
    return 0;
}

class concurs_on : public activitate {
protected://depinde
    string site;
    vector<elev> b;
    vector<int> a;
    int indice;
public:
    concurs_on();

    //ala cu parametri faci automat

    concurs_on(const concurs_on &);

    ~concurs_on();

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const concurs_on &concurs_on);

    friend istream &operator>>(istream &in, concurs_on &concurs_on);

    concurs_on &operator=(const concurs_on &);

    void adaug_elev();

    void afis_prem();

    int frauda(int l)const;
};

concurs_on::concurs_on() : activitate() {
    b.clear();
    this->site = "";
    this->indice = 0;
}

concurs_on::concurs_on(const concurs_on &concurs_on) : activitate(concurs_on), indice(concurs_on.indice),
                                                       site(concurs_on.site), b(concurs_on.b) {}

concurs_on::~concurs_on() {

}

istream &operator>>(istream &in, concurs_on &concurs_on) {
    concurs_on.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const concurs_on &concurs_on) {
    concurs_on.afisare(os);
    return os;
}

concurs_on &concurs_on::operator=(const concurs_on &concurs_on) {
    activitate::operator=(concurs_on);
    if (this != &concurs_on) {
        site = concurs_on.site;
        b = concurs_on.b;
        indice = concurs_on.indice;
    }
    return *this;
}

void concurs_on::citire(istream &in) {
    activitate::citire(in);
    cout << "\nnumar de zile pe care se desfasoara activ: ";
    int var;
    cin >> var;
    setNrZile(var);
    cout << "site: ";
    in >> site;
}

void concurs_on::afisare(ostream &os) const {
    if (frauda(0) == 1) {
        cout << "concursul este fraudat";
    }
    activitate::afisare(os);
    cout << "site: " << site << endl;
    for (auto it = b.begin(); it != b.end(); it++)
        cout << *it << " ";
    cout << " sunt " << indice << "participanti";
}

void concurs_on::adaug_elev() {
    elev el;
    cin >> el;
    b.push_back(el);
    indice++;
}

void concurs_on::afis_prem() {
    vector<int> copie;
    copie = a;
    sort(copie.begin(), copie.end());
    int ok = 0;
    for (auto j = copie.end(); j >= copie.begin(); j--) {
        if (ok == 4) {
            break;
        }
        for (int i = 0; i < a.size(); i++) {
            if (*j == a[i]) {
                cout << b[i];
                break;
            }
        }
        ok++;
    }
    copie.clear();
}

int concurs_on::frauda(int l) const{
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++) {
            if (b[i].getCnp() == b[j].getCnp()) {
                cout << "frauda";
                return 1;
            }
        }
    return 0;
}


class curs : public activitate {
protected://depinde
    vector<elev *> ab;
    int cred;
    int indi;
public:
    curs();

    //ala cu parametri faci automat

    curs(const curs &);

    ~curs();

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const curs &curs);

    friend istream &operator>>(istream &in, curs &curs);

    curs &operator=(const curs &);

    void adaug_prof();

    void adaug_elev();
};

curs::curs() : activitate() {
    ab.clear();
    this->cred = 0;
    this->indi = 0;
}

curs::curs(const curs &curs) : activitate(curs), ab(curs.ab), cred(curs.cred), indi(curs.indi) {}

curs::~curs() {

}

istream &operator>>(istream &in, curs &curs) {
    curs.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const curs &curs) {
    curs.afisare(os);
    return os;
}

curs &curs::operator=(const curs &curs) {
    activitate::operator=(curs);
    if (this != &curs) {
        cred = curs.cred;
        ab = curs.ab;
        indi = curs.indi;
    }
    return *this;
}

void curs::citire(istream &in) {
    activitate::citire(in);
    cout << "\n crdite disponibile";
    in >> cred;
}

void curs::afisare(ostream &os) const {
    activitate::afisare(os);
    os << "\ncrdite curs" << cred;
    for (int it=0;it<ab.size();it++) {

        cout <<* ab[it];
    }
}

void curs::adaug_prof() {
    elev *nou = new profesor;
    cin >> *nou;
    if (dynamic_cast<profesor *>(nou)) {

        ab.push_back(nou);
        indi++;

    }
}

void curs::adaug_elev() {
    elev *nou = new elev;
    cin >> *nou;
    if (dynamic_cast<elev *>(nou)) {

        ab.push_back(nou);
        indi++;

    }
}

void menu() {
    vector<activitate *> program;
    vector<concurs_off> v1;
    vector<concurs_on>v2;
    vector<curs>v3;
    cout<<"am facut doar prima optiune.\n";
    string optiune = "da";
    while (optiune == "da") {
        cout<<"doriti sa creati o activitate intai?(da/nu)";
        string rasp;
        cin.get();
        getline(cin,rasp);
        if(rasp=="da"){
            cout<<"ce tip de activitate doriti?(concurs online/concurs offline,curs)";
            string o;
            getline(cin,o);
            if(o=="concurs online"){
               concurs_on c;
                cin>>c;

                cout<<"cati elevi doriti sa adaugati";
                int n;
                cin>>n;
                for(int i=0;i<n;i++){
                    c.adaug_elev();
                }

            v2.push_back(c);}
            if(o=="concurs offline"){
                 concurs_off b;
                cin>>b;

                cout<<"cati elevi doriti sa adaugati";
                int n;
                cin>>n;
                for(int i=0;i<n;i++){
                    b.adaug_elev();
                }
                v1.push_back(b);
            }
            if(o=="curs"){
                 curs d;
                cin>>d;

                cout<<"cati elevi doriti sa adaugati";
                int n;
                cin>>n;
                for(int i=0;i<n;i++){
                    d.adaug_elev();
                }
                cout<<"cati profi doriti sa adaugati";
                int n1;
                cin>>n1;
                for(int i=0;i<n;i++){
                    d.adaug_prof();
                }
                v3.push_back(d);
            }
    }
        cout<<"continuati?";
        getline(cin,optiune);
        if(optiune!="da"){
           cout<<"concurs off";
       for(auto it=v1.begin();it!=v1.end();it++)
        cout<<*it;
       cout<<"concurs_on";
            for(auto it=v1.begin();it!=v1.end();it++)
                cout<<*it;
            cout<<"curs";
            for(auto it=v1.begin();it!=v1.end();it++)
                cout<<*it;
        }
    }
}

int main() {
    menu();
}

