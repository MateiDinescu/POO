#ifndef CATALOG_H_INCLUDED
#define CATALOG_H_INCLUDED

#include <bits/stdc++.h>

#include "ExamenFinal.h"

using namespace std;

template <class C>

class Catalog;

template <class C>
istream& operator>>(istream &in, Catalog<C> &c);

template <class C>

class Catalog
{
    static int i;
    int nr_matricol;
    int nr_examen;
    vector<C> structura;
    static unordered_map<int, vector<string>> cat;

public:
    Catalog();
    Catalog(const Catalog& copie);
    ~Catalog();
    Catalog operator=(const Catalog& alt);
    friend istream& operator>> <>(istream &in, Catalog &c);
    void afisare();
    int get_nr_matricol();
    int get_nr_examene();
    Catalog operator+=(const C &fisa);
    void set_umap(string);
    void afisez_umap();
};


template <class C>
int Catalog<C>::i=0;

template <class C>
Catalog<C>::Catalog()
{
    i++;
    nr_examen = 0;
    nr_matricol = i;
}

template <class C>
Catalog<C>::Catalog(const Catalog& copie)
{
    nr_matricol = copie.nr_matricol;
    structura = copie.structura;
    cat = copie.cat;
}

template <class C>
Catalog<C>::~Catalog()
{
    nr_matricol = 0;
    nr_examen = 0;
    structura.clear();
}

template<class C>
Catalog<C> Catalog<C>::operator=(const Catalog& alt)
{
    if(this != &alt)
    {
        nr_matricol = alt.nr_matricol;
        structura = alt.structura;
        cat = alt.cat;
    }
    return *this;
}

template<class C>
int Catalog<C>::get_nr_matricol()
{
    return nr_matricol;
}

template<class C>
int Catalog<C>::get_nr_examene()
{
    return nr_examen;
}

template<class C>
void Catalog<C>::afisare()
{
    cout<<"Numarul matricol este: "<<nr_matricol<<"\n";
    if(structura.empty() == true)
        cout<<"Studentul nu a sustinut examene"<<endl;
    else
    {
        cout<<"Studentul a sustinut examenele: "<<endl;
        for(auto &it: structura)
        {

            it.afisare();

        }
    }

}

template<class C>
Catalog<C> Catalog<C>::operator+=(const C &alt)
{



    nr_examen++;
    structura.push_back(alt);
    return *this;

}

template <class C>
istream&operator>> (istream &in, Catalog<C>&alt)
{
    cout<<"Numarul matricol: "<<endl;
    in>>alt.nr_matricol;
    cout<<"Numarul de examene sustinute: ";
    in>>alt.nr_examen;
    for(int i = 0; i <alt.nr_examen; i++)
    {
        C x;
        cout<<"Examenul: ";
        in>>x;
    }

    return in;
}

template<class C>
unordered_map<int, vector<string>> Catalog<C>::cat = {{ 0, {""} }};

template<class C>
void Catalog<C>::set_umap(string nume)
{
    for (unsigned i=0; i<structura.size(); i++)
    {
        if (cat.find(structura[i].get_id()) == cat.end())
        {
            cat.insert({ structura[i].get_id(), {""} });
        }

        if(structura[i].get_medie() <5 || structura[i].get_nota_s()<5)
        {
            cat[structura[i].get_id()].push_back(nume);
        }




    }


}

template<class C>
void Catalog<C>::afisez_umap()
{
    for(const auto& p : cat)
    {
        if(p.first != 0)
        {
            cout << p.first << ":";
            for(const auto& i : p.second)
            {
                cout << i;
            }
            cout<<endl;
        }
    }
}


#endif
