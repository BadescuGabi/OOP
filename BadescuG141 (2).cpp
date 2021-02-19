#include <iostream>
#include <map>
#include <iterator>
#include <vector>

using namespace std;
//Badescu George-Gabriel 141
//codeblocks 13:12
//Gcc compiler cu fla gcc c=++11


class bilet {
protected:
    string st_pl;
    string st_sos;
    string data;
    string ora;
    string cod_t;
    double durata;
    double distanta;
    double pret;
    static int index;
    int nr;
public:
    const string &getCodT() const;

public:
    bilet();

    double getDistanta() const;

    int getNr() const;

    bilet(const bilet &);

    bilet(const string &stPl, const string &stSos, const string &data, const string &ora, const string &codT,
          double durata, double distanta, double pret);

    virtual ~bilet();

    virtual void citire(istream &in);

    virtual void afisare(ostream &os) const;

    friend std::istream &operator>>(std::istream &in, bilet &bilet);

    friend std::ostream &operator<<(std::ostream &os, const bilet &bilet);

    bilet &operator=(const bilet &bilet);

    void setPret(double pret);
};

int bilet::index = 0;

void bilet::setPret(double pret) {
    bilet::pret = pret;
}

bilet::bilet(const string &stPl, const string &stSos, const string &data, const string &ora, const string &codT,
             double durata, double distanta, double pret) : st_pl(stPl), st_sos(stSos), data(data), ora(ora),
                                                            cod_t(codT),
                                                            durata(durata), distanta(distanta), pret(pret) {
    index++;
    this->nr = index;
}

bilet::bilet() {
    this->data = "";
    this->ora = "";
    this->cod_t = "";
    this->st_pl = "";
    this->st_sos = "";
    this->pret = 0;
    this->distanta = 0;
    this->durata = 0;
    index++;
    this->nr = index;
}

bilet::bilet(const bilet &bilet) : st_pl(bilet.st_pl), st_sos(bilet.st_sos), data(bilet.data), ora(bilet.ora),
                                   cod_t(bilet.cod_t),
                                   durata(bilet.durata), distanta(bilet.distanta), pret(bilet.pret), nr(bilet.nr) {}

bilet::~bilet() {}

std::istream &operator>>(std::istream &in, bilet &bilet) {
    bilet.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &os, const bilet &bilet) {
    bilet.afisare(os);
    return os;
}

bilet &bilet::operator=(const bilet &bilet) {
    if (this != &bilet) {
        st_pl = bilet.st_pl;
        st_sos = bilet.st_sos;
        data = bilet.data;
        ora = bilet.ora;
        cod_t = bilet.cod_t;
        durata = bilet.durata;
        distanta = bilet.distanta;
        pret = bilet.pret;
        nr = bilet.nr;
    }
    return *this;
}

void bilet::citire(istream &in) {
    cout << "\n" << "statie plecare: ";
    cin.get();
    getline(in, st_pl);
    cout << "statie sosire: ";
    getline(in, st_sos);
    cout << "data: ";
    getline(in, data);
    cout << "ora: ";
    getline(in, ora);
    cout << "cod_t";
    getline(in, cod_t);
    cout<<"durata :";
    in >> durata;
    cout << "distanta: ";
    in >> distanta;

}

void bilet::afisare(ostream &os) const {
    os << "statie plecare: " << st_pl << " statie sosire: " << st_sos << " data: " << data << " ora: " << ora
       << " cod tren: " << cod_t << " durata: " << durata << " distanta: " << distanta << " pret: " << pret
       << " numarul " << nr;
}

int bilet::getNr() const {
    return nr;
}

double bilet::getDistanta() const {
    return distanta;
}

const string &bilet::getCodT() const {
    return cod_t;
}

class cls_1 : public bilet {

public:
    cls_1();

    cls_1(const cls_1 &);

    ~cls_1();

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const cls_1 &cls_1);

    friend istream &operator>>(istream &in, cls_1 &cls_1);

    cls_1 &operator=(const cls_1 &);
};

cls_1::cls_1() : bilet() {}

cls_1::cls_1(const cls_1 &cls_1) : bilet(cls_1) {}

cls_1::~cls_1() {

}

istream &operator>>(istream &in, cls_1 &cls_1) {
    cls_1.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const cls_1 &cls_1) {
    cls_1.afisare(os);
    return os;
}

cls_1 &cls_1::operator=(const cls_1 &cls_1) {
    bilet::operator=(cls_1);
    if (this != &cls_1) {

    }
    return *this;
}

void cls_1::citire(istream &in) {
    bilet::citire(in);
}

void cls_1::afisare(ostream &os) const {
    bilet::afisare(os);
    cout << "\n" << "biletul ales ofera un cnfort crescut si acces la vagonul restaurant al trenului";
}

class cls_2 : public bilet {
protected://depinde

public:
    cls_2();

    //ala cu parametri faci automat

    cls_2(const cls_2 &);

    ~cls_2();

    void citire(istream &in) override;

    void afisare(ostream &os) const override;

    friend ostream &operator<<(ostream &os, const cls_2 &cls_2);

    friend istream &operator>>(istream &in, cls_2 &cls_2);

    cls_2 &operator=(const cls_2 &);
};

cls_2::cls_2() : bilet() {}

cls_2::cls_2(const cls_2 &cls_2) : bilet(cls_2) {}

cls_2::~cls_2() {

}

istream &operator>>(istream &in, cls_2 &cls_2) {
    cls_2.citire(in);
    return in;
}

ostream &operator<<(ostream &os, const cls_2 &cls_2) {
    cls_2.afisare(os);
    return os;
}

cls_2 &cls_2::operator=(const cls_2 &cls_2) {
    bilet::operator=(cls_2);
    if (this != &cls_2) {

    }
    return *this;
}

void cls_2::citire(istream &in) {
    bilet::citire(in);
}

void cls_2::afisare(ostream &os) const {
    bilet::afisare(os);
}


class tren {
protected:
    //variabile
public:
    tren();

    //genereaza l automat pe ala cu parametri

    tren(const tren &);

    virtual ~tren();

    virtual void citire(istream &in) = 0;

    virtual void afisare(ostream &os) const = 0;

    friend std::istream &operator>>(std::istream &in, tren &tren);

    friend std::ostream &operator<<(std::ostream &os, const tren &tren);

    tren &operator=(const tren &tren);
};

tren::tren() {}

tren::tren(const tren &tren) {}

tren::~tren() {}

std::istream &operator>>(std::istream &in, tren &tren) {
    tren.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &os, const tren &tren) {
    return os;
}

tren &tren::operator=(const tren &tren) {
    if (this != &tren) {

    }
    return *this;
}


class regio : public tren {
protected:
    vector<bilet *> vec;
    vector<string> v;
public:
    regio();

    regio(const regio &);

    virtual ~regio();

    virtual void citire(istream &in);

    virtual void afisare(ostream &os) const;

    friend std::istream &operator>>(std::istream &in, regio &regio);

    friend std::ostream &operator<<(std::ostream &os, const regio &regio);

    regio &operator=(const regio &regio);

    void adauga_bilet();

    int verif_bil(int o,string dat);

    int verif_dist(int o,double dat);
};

regio::regio() : tren() {
    vec.clear();
    v.clear();
}

regio::regio(const regio &regio) : tren(regio), vec(regio.vec), v(regio.v) {}

regio::~regio() {}

std::istream &operator>>(std::istream &in, regio &regio) {
    regio.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &os, const regio &regio) {
    regio.afisare(os);
    return os;
}

regio &regio::operator=(const regio &regio) {
    tren::operator=(regio);
    if (this != &regio) {
        vec = regio.vec;
        v = regio.v;
    }
    return *this;
}

void regio::citire(istream &in) {

}

void regio::afisare(ostream &os) const {
    cout << "\n" << "trenul regio circula pe distante medii si mici si opreste in toate statiile!!\n";
    cout << "bilete trnului sunt";
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << **it;
    cout << "\n iar seriile corespunzatoare sunt:";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it;
}

void regio::adauga_bilet() {

    cout << "ce tip de bilet doriti sa adaugati (clasa): 1/2";
    int opt;
    cin >> opt;
    string a = "R";
    if (opt == 1) {
        bilet *p = new cls_1;
        cin >> *p;
        p->setPret(p->getDistanta() * 0.39 + (1 / 5) * ((p->getDistanta() * 0.39)));
        vec.push_back(p);
        if (dynamic_cast<cls_1 *>(p)) {
            a += "I-";
            string str = to_string(p->getNr());
            a += str;
        }
    }
    if (opt == 2) {
        bilet *p = new cls_2;
        cin >> *p;
        p->setPret(p->getDistanta() * 0.39);
        vec.push_back(p);
        if (dynamic_cast<cls_2 *>(p)) {
            a += "II-";
            string str = to_string(p->getNr());
            a += str;
        }
    }
    v.push_back(a);
}

int regio::verif_bil(int o,string dat) {
    for (int i=o;i<vec.size();i++)
    if(vec[i]->getCodT()==dat){
        cout<<*vec[i];
        return 1;}
    return 0;
}

int regio::verif_dist(int o, double dat) {
    for (int i=o;i<vec.size();i++)
        if(vec[i]->getDistanta()>dat){
            cout<<*vec[i];
            return 1;}
    return 0;

}


class inter_r : public tren {
protected:
    vector<bilet *> vec;
    int loc;
    vector<string> v;
public:
    inter_r();

    inter_r(const inter_r &);

    virtual ~inter_r();

     void citire(istream &in);

     void afisare(ostream &os) const;

    friend std::istream &operator>>(std::istream &in, inter_r &inter_r);

    friend std::ostream &operator<<(std::ostream &os, const inter_r &inter_r);

    inter_r &operator=(const inter_r &inter_r);

    void adaug_bilet();

    int verif_bil(int o,string dat);

    int verif_dist(int o,double dat);
};

inter_r::inter_r() : tren() {
    vec.clear();
    this->loc = 0;
    v.clear();
}

inter_r::inter_r(const inter_r &inter_r) : tren(inter_r), vec(inter_r.vec), loc(inter_r.loc), v(inter_r.v) {}

inter_r::~inter_r() {}

std::istream &operator>>(std::istream &in, inter_r &inter_r) {
    inter_r.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &os, const inter_r &inter_r) {
    inter_r.afisare(os);
    return os;
}

inter_r &inter_r::operator=(const inter_r &inter_r) {
    tren::operator=(inter_r);
    if (this != &inter_r) {
        vec = inter_r.vec;
        loc = inter_r.loc;
    }
    return *this;
}

void inter_r::citire(istream &in) {
    cout << "\n introduceti locul biletului";
    in >> loc;
}

void inter_r::afisare(ostream &os) const {
    cout << "\n" << "trenul inter_r circula pe distante medii si lungi si opreste in toate statiile!!\n";
    cout << "bilete trnului sunt";
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << **it;
    cout << "\n";
    cout << "seriile lor sunt: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it;
}

void inter_r::adaug_bilet() {
    cout << "ce tip de bilet doriti sa adaugati (clasa): 1/2";
    int opt;
    cin >> opt;
    string a = "IR";
    if (opt == 1) {
        bilet *p = new cls_1;
        cin >> *p;
        p->setPret(p->getDistanta() * 0.7 + (1 / 5) * ((p->getDistanta() * 0.7)));
        vec.push_back(p);
        if (dynamic_cast<cls_1 *>(p)) {
            a += "I-";
            string str = to_string(p->getNr());
            a += str;
        }
    }
    if (opt == 2) {
        bilet *p = new cls_2;
        cin >> *p;
        p->setPret(p->getDistanta() * 0.7);
        vec.push_back(p);
        if (dynamic_cast<cls_2 *>(p)) {
            a += "II-";
            string str = to_string(p->getNr());
            a += str;
        }
    }
    v.push_back(a);
}

int inter_r::verif_bil(int o,string dat) {
    for (int i=o;i<vec.size();i++)
        if(vec[i]->getCodT()==dat){
            cout<<*vec[i];
            return 1;}
    return 0;
}

int inter_r::verif_dist(int o, double dat) {
    for (int i=o;i<vec.size();i++)
        if(vec[i]->getDistanta()>dat){
            cout<<*vec[i];
            return 1;}
    return 0;

}

void menu() {
    vector<regio> k;
    vector<inter_r> t;
    string op = "da";
    vector<tren*>manag;
    while (op == "da") {
        cout << "A.\tEliberarea unui nou bilet completând corect toate datele necesare;\n"
                "B.\tListarea biletelor eliberate pentru un anumit tren (folosind codul trenului);\n"
                "C.\tListarea biletelor eliberate pentru călătorii pe o distanța mai mare ca o valoare dată;\n"
                "D.\tAnularea unui bilet folosind seria biletului;"<<"\n";
        string opt;
        getline(cin,opt);
            if(opt=="A"){
                cout<<"la ce tip de tren va fi biletul?I/R";
                string opt2;
                getline(cin,opt2);
                if(opt2=="I"){
                    inter_r m;
                    m.adaug_bilet();
                    t.push_back(m);
                }
                if(opt2=="R"){
                    regio n;
                    n.adauga_bilet();
                    k.push_back(n);
                }
            }
            if(opt=="B"){
                string co;
                cout<<"cautati tren dupa cod";

                getline(cin,co);
                for (auto it =k.begin(); it!=k.end() ; it++) {
                    for(int i=0;i<100;i++){
                        it->verif_bil(i,co);
                    }
                }
                cout<<"\n";
                for (auto it =t.begin(); it!=t.end() ; it++) {
                    for(int i=0;i<100;i++){
                        it->verif_bil(i,co);
                    }
                }

            }
            if(opt=="C"){
                double distanta;
                cout<<"distanta cautata este: ";
                cin>>distanta;

                for (auto it =k.begin(); it!=k.end() ; it++) {
                    for(int i=0;i<100;i++){
                        it->verif_dist(i,distanta);
                    }
                }
                cout<<"\n";
                for (auto it =t.begin(); it!=t.end() ; it++) {
                    for(int i=0;i<100;i++){
                        it->verif_dist(i,distanta);
                    }
                }
            }
        cout << "continuati";
        cin.get();
        getline(cin, op);
        if(op!="da"){
            cout<<"se face afisarea: ";
            for (auto it =k.begin(); it!=k.end() ; it++) {
                    cout<<*it;
            }
            cout<<"\n";
            for (auto it =t.begin(); it!=t.end() ; it++) {
                cout<<*it;
            }
        }
    }
}

int main() {
    menu();
}
