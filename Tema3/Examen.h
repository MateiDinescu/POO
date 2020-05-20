#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class Examen
{
protected:
    static int i;
    int id;
    string Materie;
    float nota_scris;

public:
    Examen(string materie = "", float nota_scris = 0.00);
    Examen(const Examen &copie);
    ~Examen();

    string get_materie()const;
    int get_id()const;
    float get_nota_s()const;
    void set_id(const int);
    void set_materie(const string);
    void set_nota_s(const float);
    void verificare();
    Examen operator=(const Examen &e);
    friend istream& operator>>(istream &in, Examen &e);
    friend ostream& operator<<(ostream &out, Examen &e);
    void vnota();
    virtual float get_medie();
    virtual void afisare();


};



#endif
