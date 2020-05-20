#include "ExamenFinal.h"

#include <bits/stdc++.h>

using namespace std;

ExamenFinal::ExamenFinal(string materie, float notascrisa, float notaoral , float punctebonus):Partial(materie,notascrisa,notaoral), puncte_bonus(punctebonus){}

ExamenFinal::ExamenFinal(const ExamenFinal &copie):Partial(copie), puncte_bonus(copie.puncte_bonus){}

ExamenFinal::~ExamenFinal()
{
    puncte_bonus = 0;
}

ExamenFinal& ExamenFinal::operator=(const ExamenFinal &alt)
{
    if(this!=&alt)
    {
        Materie = alt.Materie;
        id = alt.id;
        nota_scris = alt.nota_scris;
        puncte_bonus = alt.puncte_bonus;
    }

    return *this;
}

istream& operator>>(istream &in, ExamenFinal &ef)
{
    in>>dynamic_cast<Partial&>(ef);
    cout<<"Numarul de puncte bonus pe care le are elevul este: ";
    in>>ef.puncte_bonus;
    return in;
}

ostream& operator<<(ostream &out, ExamenFinal &ef)
{
    out<<"Numarul de puncte bonus pe care le are elevul este: "<<ef.puncte_bonus<<endl;
    return out;
}

float ExamenFinal::medie()
{
    return(get_nota_o() + get_nota_s())/2 + puncte_bonus;
}
