#include "Partial.h"

using namespace std;

Partial::Partial(string materie, float notascris, float notaoral): Examen(materie, notascris), nota_oral(notaoral){}

Partial::Partial(const Partial& copie):Examen(copie), nota_oral(copie.nota_oral){}

Partial::~Partial()
{
    nota_oral = 0;
}

Partial& Partial::operator=(const Partial& alt)
{
    Materie = alt.Materie;
    id = alt.id;
    nota_scris = alt.nota_scris;
    nota_oral = alt.nota_oral;
    return *this;
}

istream& operator>>(istream &in, Partial &p)
{
    in>>dynamic_cast<Examen&>(p);
    cout<<"Nota obtinuta la testul oral este: ";
    in>>p.nota_oral;
    return in;
}

ostream& operator<<(ostream &out, Partial &p)
{
    out<<"Nota obtinuta la testul oral este: "<<p.nota_oral<<endl;
    return out;
}
