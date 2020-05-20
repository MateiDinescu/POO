#ifndef PARTIAL_H_INCLUDED
#define PARTIAL_H_INCLUDED

#include "Examen.h"
#include <bits/stdc++.h>
using namespace std;

class Partial:public Examen
{
protected:
    float nota_oral;

public:
    float get_nota_o() const {return nota_oral;}
    Partial(string materie = "" , float nota_scris = 0 , float nota_oral = 0);
    Partial(const Partial& copie);
    ~Partial();
    Partial& operator=(const Partial& alt);
    friend istream& operator>>(istream &in, Partial &p);
    friend ostream&  operator<<(ostream &out, Partial &p);
    virtual void afisare()override
    {
        cout<<"La examenul cu id-ul: "<<get_id()<<" la materia: "<<get_materie()<<" , nota la testul scris este: "<<get_nota_s()<<" , iar nota la testul oral este: "<<nota_oral<<endl;
    }

};


#endif
