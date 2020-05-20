#include "Examen.h"
#include "Partial.h"
#include "ExamenFinal.h"

#include <bits/stdc++.h>
#include <exception>
using namespace std;

int Examen:: i = 0;

Examen::Examen(string materie, float nota):Materie(materie), nota_scris(nota)
{
    i++;
    id = i;
}

Examen::Examen(const Examen &copie)
{
    id = copie.id;
    Materie = copie.Materie;
    nota_scris = copie.nota_scris;
}

Examen::~Examen()
{
    id = 0;
    Materie.clear();
    nota_scris = 0.00;
}

string Examen::get_materie() const
{
    return Materie;
}

int Examen::get_id() const
{
    return id;
}

float Examen::get_nota_s() const
{
    return nota_scris;
}

void Examen::set_id(const int id_nou)
{
    id = id_nou;
}

void Examen::set_materie(const string materie)
{
    Materie = materie;
}

void Examen::set_nota_s(const float nota)
{
    if( nota >= 0 && nota <= 10 )
        nota_scris = nota;
}

void Examen::verificare()
{
    if(nota_scris > 10 || nota_scris < 0)
        throw 0;
}

Examen Examen::operator=(const Examen &e)
{
    if(this!=&e)
    {
        this->id = e.id;
        this->nota_scris = e.nota_scris;
        this->Materie = e.Materie;
    }
    return *this;
}

istream& operator>>(istream &in,Examen &e)
{
    cout<<"Materia: ";
    in>>e.Materie;
    cout<<"Nota obtinuta la testul scris: ";
    in>>e.nota_scris;
    /*
    try
    {
        e.verificare();
    }
    catch(int)
    {
        cout<<"Nota a fost introdusa gresit; Tipul notei este float!"<<endl;
        in>>e.nota_scris;
    }
    catch(...)
    {
        cout<<"Nota a fost introdusa gresit"<<endl;
        in>>e.nota_scris;
    }
    */
    return in;
}

ostream& operator<<(ostream &out, Examen &e)
{
    out<<"ID examen: "<<e.id<<endl<<"Materie: "<<e.Materie<<endl<<"Nota testului scris: "<<e.nota_scris<<endl;
    return out;
}

float Examen::get_medie()
{
    return nota_scris;
}

void Examen::afisare()
{
    cout<<"La examenul cu id-ul: "<<id<<" la materia: "<<Materie<<" nota la testul scris este: "<<nota_scris<<endl;
}
