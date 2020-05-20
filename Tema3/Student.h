#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <bits/stdc++.h>

#include "Catalog.h"

using namespace std;

class Student
{
private:
    string Nume;
    string Prenume;
    int nr_grupa;
    Catalog<Examen>examen;
    Catalog<Partial>partial;
    Catalog<ExamenFinal>examen_final;

public:
    Student(string nume = "", string prenume = "", int nr_grupa = 0);
    Student(const Student& copie);
    ~Student();
    Student& operator=(const Student& alt);
    friend istream& operator>>(istream& in, Student &s);
    friend ostream& operator<<(ostream& out, Student &s);
    string get_nume();
    void add_examen(Examen);
    void add_partial(Partial);
    void add_final(ExamenFinal);
    void examen_picat();
    void partial_picat();
    void examenfinal_picat();
    void afisarea(Student &s);


};



#endif
