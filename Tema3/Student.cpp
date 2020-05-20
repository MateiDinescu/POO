#include "Student.h"
#include <bits/stdc++.h>
using namespace std;

Student::Student(string nume, string prenume, int grupa): Nume(nume), Prenume(prenume), nr_grupa(grupa){}


Student::Student(const Student& copie)
{
    Nume = copie.Nume;
    Prenume = copie.Prenume;
    nr_grupa = copie.nr_grupa;
}
Student::~Student()
{
    nr_grupa=0;
    Nume.clear();
    Prenume.clear();
}

Student& Student::operator=(const Student& alt)
{
    if(this == &alt)
        return *this;
    this->Nume = alt.Nume;
    this->Prenume = alt.Prenume;
    this->nr_grupa = alt.nr_grupa;
    return *this;
}

istream& operator>>(istream& in, Student &s)
{
    cout<<"Nume: ";
    in>>s.Nume;
    cout<<"Prenume: ";
    in>>s.Prenume;
    cout<<"Face parte din grupa: ";
    in>>s.nr_grupa;
    return in;
}

string Student::get_nume()
{
    return Nume;
}

void Student::add_examen(Examen e)
{
    examen += e;
}

void Student::add_partial(Partial p)
{
    partial += p;
}

void Student::add_final(ExamenFinal ef)
{
    examen_final += ef;
}

void Student::examen_picat()
{
    examen.set_umap(get_nume());
    examen.afisez_umap();
}

ostream& operator<<(ostream& out, Student &s)
{
    out<<"Nume: "<<s.Nume<<endl<<"Prenume: "<<s.Prenume<<endl<<"Din grupa: "<<s.nr_grupa<<endl;
    return out;

}

