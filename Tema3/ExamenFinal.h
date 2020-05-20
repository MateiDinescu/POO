#ifndef EXAMENFINAL_H_INCLUDED
#define EXAMENFINAL_H_INCLUDED

#include <bits/stdc++.h>

#include "Partial.h"

using namespace std;

class ExamenFinal:public Partial
{
private:
    float puncte_bonus;

public:
    float get_puncte_bonus()const {return puncte_bonus;}
    ExamenFinal(string Materie = "", float nota_scris = 0, float nota_oral = 0 , float puncte_bonus = 0);
    ExamenFinal(const ExamenFinal& copie);
    ~ExamenFinal();
    ExamenFinal& operator=(const ExamenFinal& alt);
    friend istream& operator>>(istream &in, ExamenFinal &ef);
    friend ostream& operator<<(ostream &out, ExamenFinal &ef);
    virtual void afisare()override
    {
        cout<<"La examenul cu id-ul: "<<get_id()<<" la materia: "<<get_materie()<<" , nota la testul scris este: "<<get_nota_s()<<" , iar nota la testul oral este: "<<nota_oral<<" , iar nota la examenul final este: "<<puncte_bonus<<endl;
    }
    float medie();
};

#endif
