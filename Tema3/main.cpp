#include <bits/stdc++.h>


#include "Student.h"
#include "Examen.h"
#include "Partial.h"
#include "ExamenFinal.h"
#include "Catalog.h"

using namespace std;

int main()
{
    Student s1("Dinescu","Matei",2);
    Examen e1("POO",7.80);
    Examen e2("SD",6.40);
    Partial p1("LFA",6.30,9.20);
    ExamenFinal ef("Mate",5.40,7.20,1.5);
    s1.add_examen(e1);
    s1.add_examen(e1);
    s1.add_partial(p1);
    s1.add_final(ef);
    cout<<s1;
    return 0;
}
