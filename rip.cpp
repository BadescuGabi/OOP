#include <iostream>
#include <cstring>
#include <vector>
#include<iterator>
#include <stdlib.h>
using namespace std;
///-----------------locuinta-------

class locuinta
{
protected:
    string nume_client;
    double suprafata_utila;
    int discount;
public:
    locuinta(string l_nume, double l_suprafata, int l_discount);
    locuinta(const locuinta& ob);
    virtual ~locuinta();

    virtual void chirie(double)=0;
    virtual void citire (istream &in)=0;
    virtual void afisare(ostream &out)=0;


    locuinta& operator= (locuinta &ob);

    friend istream& operator>>(istream&, locuinta&);
    friend ostream& operator<<(ostream&, locuinta&);

};
locuinta::locuinta(string l_nume="", double l_suprafata=0, int l_discount=0)
{
    nume_client=l_nume;
    suprafata_utila=l_suprafata;
    try
    {
        if(l_discount<0 || l_discount >10)
            throw l_discount;
    }
    catch (int x)
    {
        cout<<"Discountul oferit nu se afla in intervalul disponibil";
        exit(EXIT_FAILURE);
    }
    discount=l_discount;
    /* cout<<"Constructor cu parametrii";
     cout<<endl;
     cout<<nume_client<<" "<<suprafata_utila<<" "<<discount<<endl;*/
}
locuinta::~locuinta()
{
    nume_client="";
    suprafata_utila=0;
    discount=0;
    /*cout<<"Destructor"<<endl;
    cout<< nume_client<<" "<<suprafata_utila<<" "<<discount<<endl;*/
}
locuinta::locuinta(const locuinta& ob)
{
    nume_client=ob.nume_client;
    suprafata_utila=ob.suprafata_utila;
    discount=ob.discount;
    /* cout<<"Copy constructor"<<endl;
     cout<< nume_client<<" "<<suprafata_utila<<" "<<discount<<endl;*/
}
locuinta& locuinta::operator=(locuinta &ob)
{
    if (this!=&ob)
    {
        nume_client=ob.nume_client;
        suprafata_utila=ob.suprafata_utila;
        discount=ob.discount;
    }
    return *this;
}
istream& operator>>(istream& in, locuinta& f)
{
    f.citire(in);
    return in;
}
ostream& operator<<(ostream& out, locuinta& f)
{
    f.afisare(out);
    return out;
}


///------------clasa apartament--------


class apartament: public locuinta
{
private:
    double pret_chirie;
    int etajul_locuintei;
public:
    apartament();
    apartament(string l_nume, int l_suprafata, int l_discount, int l_etaj_loc, double l_pret);
    apartament(apartament &ob);
    ~apartament();

    void chirie(double);
    void citire(istream &in);
    void afisare(ostream &out);

    apartament& operator= (apartament &ob);

};
apartament& apartament::operator= (apartament &ob)
{

    if (this!=&ob)
    {
        locuinta::operator=(ob);
        pret_chirie=ob.pret_chirie;
        etajul_locuintei=ob.etajul_locuintei;
    }
    return *this;

}
apartament::apartament()
{

    ///cout<<"Constructor fara parametrii a clasei apartament";
    etajul_locuintei=0;
    pret_chirie=0;

}
apartament::apartament(string l_nume, int l_suprafata, int l_discount, int l_etaj_loc=0, double l_pret=0):locuinta(l_nume, l_suprafata, l_discount)
{
    etajul_locuintei=l_etaj_loc;
    pret_chirie=l_pret;
    /*cout<<"Constructor cu parametrii a clasei apartament"<<endl;
    cout<<l_nume<<" "<<l_suprafata<<" "<<l_discount<<" "<<l_etaj_loc<<endl;*/
}
apartament::apartament(apartament &ob):locuinta(ob)
{
    etajul_locuintei=ob.etajul_locuintei;
    pret_chirie=ob.pret_chirie;
    ///cout<<"Constructor de copiere";
}
apartament::~apartament()
{
    //cout<<"Destructor al clasei apartament"<<endl;
    etajul_locuintei=0;
    pret_chirie=0;
    //cout<<etajul_locuintei<<endl;
}
void apartament::chirie(double pret_chirie)
{
    double suma_chirie;
    if(discount==0)
    {
        suma_chirie=pret_chirie*suprafata_utila;
        cout<<"     Chiria este in valuare de " <<suma_chirie;
    }
    else
    {
        suma_chirie=pret_chirie*suprafata_utila-(pret_chirie*suprafata_utila*discount)/100;
        cout<<"     Chiria este in valuare de " <<suma_chirie;
    }
}
void apartament::citire(istream &in)
{
    int a;
    double b;
    string n;
    cout<<"     Citim numele clientului : ";
    cin>>n;
    nume_client=n;
    cout<<"     Citim suprafata utila: ";
    in>>b;
    suprafata_utila=b;
    cout<<"     Citim valuarea discountului: ";
    in>>a;
    discount=a;
    try
    {
        if (discount<0||discount>10)
            throw discount;
    }
    catch (int i)
    {
        cout<<"   Discountul nu se afla in intervalul posibil. Va rugam sa oferiti alt discount: ";
        in>>a;
        discount=a;

    }
    int x;
    cout<<"     Citim etajul la care se afla: ";
    in>>x;
    double y;
    etajul_locuintei=x;
    cout<<"     Da-ti pretul pe m^2 pentru apartament:";
    in>>y;
    pret_chirie=y;

}
void apartament::afisare(ostream &out)
{
    cout<<"     Numele clientului este:"<<nume_client;
    cout<<endl;
    cout<<"     Suprafata utila este: " <<suprafata_utila;
    cout<<endl;
    cout<<"     Se ofera un discount de :" <<discount<<"%";
    cout<<endl;
    cout<<"     Etajul la care se afla apartamentul este: ";
    out<<etajul_locuintei;
    cout<<endl;
    chirie(pret_chirie);
}

///-----------CASA-----

class casa:public locuinta
{
private:
    double pret_chirie;
    double suprafata_curte;
    int nr_etaje;
    vector<double> v;
    double suma_chirie;
public:
    casa();
    casa(vector<double> vc, string l_nume, int l_suprafata, int l_discount, int l_nr, double l_pret, double l_curte);
    casa(const casa &ob);
    ~casa();

    void chirie(double);
    int get_chirie() const
    {
        return suma_chirie;
    }
    void citire(istream &in);
    void afisare(ostream &out);

    casa& operator= (casa &ob);

};
casa& casa::operator= (casa &ob)
{

    if (this!=&ob)
    {
        locuinta::operator=(ob);
        pret_chirie=ob.pret_chirie;
        suprafata_curte=ob.suprafata_curte;
        nr_etaje=ob.nr_etaje;
    }
    return *this;

}
casa::casa()
{

    // cout<<"Constructor fara parametrii a clasei casa";
    suprafata_curte=0;
    nr_etaje=0;
    pret_chirie=0;

}
casa::casa(vector<double> l_v, string l_nume, int l_suprafata, int l_discount, int l_nr=0, double l_pret=0, double l_curte=0):locuinta(l_nume, l_suprafata, l_discount)
{
    nr_etaje=l_nr;
    pret_chirie=l_pret;
    suprafata_curte=l_curte;
    v=l_v;
    // cout<<"Constructor cu parametrii a clasei casa"<<endl;
    //  cout<<l_nume<<" "<<l_suprafata<<" "<<l_discount<<" "<<l_nr<<" "<<l_pret<<" "<<l_curte<<endl;
}
casa::casa(const casa &ob):locuinta(ob)
{
    nr_etaje=ob.nr_etaje;
    pret_chirie=ob.pret_chirie;
    suprafata_curte=ob.suprafata_curte;
    v=ob.v;
    //  cout<<"Constructor de copiere casa";
}
casa::~casa()
{
//   cout<<"Destructor al clasei apartament"<<endl;
    suprafata_curte=0;
    nr_etaje=0;
    pret_chirie=0;
    //  cout<<suprafata_curte<<" "<<nr_etaje<<" "<<pret_chirie<<endl;
}
void casa::chirie(double pret_chirie)
{
    if(discount==0)
    {
        suma_chirie=pret_chirie*suprafata_utila+pret_chirie*suprafata_curte;

    }
    else
    {
        suma_chirie=pret_chirie*suprafata_utila-(pret_chirie*suprafata_utila*discount)/100+pret_chirie*suprafata_curte;
    }
}
void casa::citire(istream &in)
{
    int a;
    double b;
    string n;
    cout<<"     Citim numele clientului : ";
    cin>>n;
    nume_client=n;
    cout<<"     Citim suprafata utila: ";
    in>>b;
    suprafata_utila=b;
    cout<<"     Citim valuarea discountului: ";
    in>>a;
    discount=a;
    try
    {
        if (discount<0||discount>10)
            throw discount;
    }
    catch (int i)
    {
        cout<<"   Discountul nu se afla in intervalul posibil. Va rugam sa oferiti alt discount: ";
        in>>a;
        discount=a;

    }
    int x;
    cout<<"     Citim numarul de etaje pe care o are clasa: ";
    in>>x;
    nr_etaje=x;
    cout<<"     Suprafata curtii este : ";
    in>>x;
    suprafata_curte=x;

    double y;
    cout<<"     Da-ti pretul pe m^2 pentru casa:";
    in>>y;
    pret_chirie=y;

}
void casa::afisare(ostream &out)
{
    cout<<"     Numele clientului este:"<<nume_client;
    cout<<endl;
    cout<<"     Suprafata utila este: " <<suprafata_utila;
    cout<<endl;
    cout<<"     Se ofera un discount de :" <<discount<<"%";
    cout<<endl;
    cout<<"     Etajul la care se afla apartamentul este: ";
    out<<nr_etaje<<endl;
    cout<<"     Suprafara curtii este:";
    out<<suprafata_curte<<endl;
    cout<<"     Chiria este:";
    out<<suma_chirie<<endl;
}
/**
    locuinta---> apartament
            ---> casa
*/
template<typename t>
class Gestiune
{
    vector<t> loc;
    static int indice;
public:
    Gestiune()
    {
        loc.clear();
    }
    ~Gestiune() {}
    Gestiune(const Gestiune<t> &ob)
    {

        loc=ob.loc;
    }

    static void nr_in()
    {
        indice+=1;
    }
    t & operator +=(t &ob)
    {
        nr_in();
        loc.push_back(ob);

    }
    static int getindice()
    {
        return indice;
    }

    template <typename u>
    friend istream &operator>>(istream &in, Gestiune<u> &ob);
    template <typename u>
    friend ostream &operator<<(ostream &out, Gestiune<u> &ob);
    Gestiune &operator =(const Gestiune &ob)
    {
        if(this != &ob)
            loc=ob.loc;
        return *this;
    }
};
template<typename t>
int Gestiune<t>::indice=0;
template <typename u>
ostream &operator<<(ostream &out, Gestiune<u> &ob)
{
    for (auto it = ob.loc.begin(); it != ob.loc.end(); it++)
        cout << **it;
}
template <typename u>
istream &operator>>(istream &in, Gestiune<u> &ob)
{
    cout<<"Introduceti obiectele: \n";
    for (int i=0; i<ob.loc.size(); i++)
    {
        in>>ob.loc[i];
        cout<<"\n";
    }
    return in;

}

///-----------------------specializare casa
template<>
class Gestiune<casa>
{   casa obiect;

    static vector<casa> caseg;
    static int numar_case;
    static int total_chirie;
public:
    Gestiune(){};
    ~Gestiune(){};
    Gestiune(const Gestiune<casa>& ob)
    {
        for (int i = 0; i < ob.caseg.size(); i++)
            caseg.push_back(ob.caseg[i]);
    }

    Gestiune& operator =(Gestiune<casa>& ob)
    {
        if (this != &ob)
            for (int i = 0; i < ob.caseg.size(); i++)
                caseg.push_back(ob.caseg[i]);
        return *this;
    }
    casa & operator +=(casa &ob)
    {

        numar_case=numar_case+1;
        caseg.push_back(ob);
        total_chirie=total_chirie+ob.get_chirie();
    }
    friend istream &operator>>(istream &in, Gestiune<casa> &ob)
    {
        cout<<"Introduceti obiectul: \n";
        cin>>ob.obiect;
        ob.caseg.push_back(ob.obiect);
        return in;

    }
    friend ostream &operator<<(ostream &out, Gestiune<casa> &ob)
    {   for (auto it = ob.caseg.begin(); it != ob.caseg.end(); it++)
            cout << *it;

        out<<endl;
        out<<total_chirie;
    }

};
int Gestiune<casa>::total_chirie=0;
int Gestiune<casa>::numar_case=0;
vector<casa> Gestiune<casa>:: caseg;

void meniu_out()
{
    cout<<"\t Agentie imobiliara";
    cout<<endl<<endl<<endl;
    cout<<"\t Meniu";
    cout<<endl;
    cout<<"0. Iesire";
    cout<<endl;
    cout<<"1. Ambele timpuri de locuinta";
    cout<<endl;
    cout<<"2. Doar apartamente";
    cout<<endl;
    cout<<"3. Doar casa";
    cout<<endl;

}
void tip(locuinta *&p, int &i, Gestiune<locuinta*> &loc)
{
    string s;
    cout<<endl;
    cout<<" Introduceti tipul locuintei dorite ";
    cin>>s;
    try
    {
        if(s=="casa")
        {
            p=new casa;
            cin>>*p;
           loc+=p;
            i++;
        }
        else if(s=="apartament")
        {
            p=new apartament;
            cin>>*p;
            loc+=p;
            i++;
        }
        else
            throw 0;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Ne pare rau, insa avem locuinte de tip casa sau apartament. ";
    }
}
void menu()
{
    int optiune_meniu=0;
    int n=0;
    locuinta **v;
    Gestiune<locuinta*> loc;
    do
    {
        meniu_out();
        cout<<"Introduceti optiunea din meniu pe care o doresti: ";
        cin>>optiune_meniu;

        if(optiune_meniu==1)
        {
            cout<<"Introduceti numarul de imobiliare dorite: ";
            cin>>n;
            v=new locuinta*[n];
            if(n>0)
            {
                for(int i=0; i<n;)
                    tip(v[i],i,loc);
                cout<<endl;
                cout<<"Afisam ceea ce am citit mai sus";
                cout<<endl;
               cout<<loc;

            }
            else
                cout<<"Puteti cauta minim o locuinta";
        }
        if(optiune_meniu==2)
        {
            //Gestiune <apartament>x;
           // cin>>x;
           // cout<<x;
        }
        if(optiune_meniu==3)
        {
            Gestiune<casa> x;
            cin>>x;
            cout<<x;
        }
        if(optiune_meniu==0)
        {
            cout<<endl;
            cout<<"EXIT";
            cout<<endl;

        }
        cout<<endl;

    }
    while(optiune_meniu!=0);
}

int main()
{
///   locuinta a, b("Popescu Ion", 45, 5), c(b);
    menu();

}

