#include <bits/stdc++.h>

using namespace std;

class Vector{
    friend class Nr_Natural_Mare;
    friend class Nr_Fibonacci_mare;
private:
    int vsize,maxsize;
    int* a;
public:
    Vector();
    Vector(int);
    Vector(const Vector&);
    ~Vector();
    int size();
    int operator[](int);
    Vector& operator=(const Vector&);
    Vector& operator+=(int);
    void push_back(int);
    void adaugare();
    friend ostream& operator<<(ostream& out, Vector& v);


};


class Nr_Natural_Mare{
public:
    Vector V;
    int nr_cif;
    Nr_Natural_Mare();
    ~Nr_Natural_Mare();
    virtual void Fib();
    virtual void Print(Nr_Natural_Mare&);
    friend ostream& operator<<(ostream& out,Nr_Natural_Mare& n);

};


class Nr_Fibonacci_mare : public Nr_Natural_Mare{
public:
    void Fib();
    void Print(Nr_Fibonacci_mare&);

};
// Functiile Clasei vector

Vector::Vector() // Constructor
{
    cout<<"Al catelea numar din sirul lui Fibonacci vrei sa fie afisat?  ";
    cin>>maxsize;
    a = new int[maxsize];
    vsize = 0;
}

Vector::Vector(int i) // Constructor
{
    maxsize = i;
    a = new int[maxsize];
    vsize = 0;
}

Vector::Vector(const Vector& v) // Copy Constructor
{
    maxsize = v.maxsize;
    vsize = v.vsize;
    a = new int[maxsize];
    for(int i=0;i<v.vsize;i++)
        a[i]=v.a[i];
}

Vector::~Vector() // Destructor
{
    delete[] a;
}

int Vector::operator[](int i)
{
    return a[i];
}

int Vector::size()
{
    return vsize;
}

void Vector::adaugare()
{
    maxsize = vsize*2;
    int* aux=new int[maxsize];
    for(int i=0;i<vsize;i++)
        aux[i]=a[i];
    delete[] a;
    a = aux;
}

void Vector::push_back(int i)
{
    if(vsize + 1 > maxsize)
        adaugare();
    a[vsize] = i;
    vsize++;
}

Vector& Vector::operator=(const Vector& v)
{
    if(this != &v)
    {
        maxsize = v.maxsize;
        vsize = v.vsize;
        delete[] a;
        a = new int[maxsize];
        for(int i=0;i<v.vsize;i++)
            a[i]=v.a[i];
    }
    return *this;
}


Vector& Vector::operator+=(int i)
{
    this->push_back(i);
    return *this;
}

ostream& operator<<(ostream& out, Vector& v)
{
    for(int i=0;i<v.vsize;i++)
    {
        out<<v[i];
        if(i != v.vsize - 1)
            out<<" + ";
    }
    out<<endl;
    return out;
}

// Functiile Clasei Nr_Natural_mare

Nr_Natural_Mare::Nr_Natural_Mare()
{
    nr_cif = V.maxsize;
}

Nr_Natural_Mare::~Nr_Natural_Mare()
{
    nr_cif = 0;
    delete[] &V;
}

void Nr_Natural_Mare::Fib()
{
    if(V.maxsize == 0)
        cout<<"Nope";
    else
        if(V.maxsize == 1)
            {V+=0; cout<<"Numarul este: 0"<<endl<<"iar descompunerea este: 0";}
        else
            if(V.maxsize == 2)
            {
                V+=0;
                V+=1;
                cout<<"Numarul este: 1"<<endl<<"Iar descompunerea lui este: 0 + 1";
            }
            else
             {
                V+=0;
                V+=1;
                int aux1,aux2,aux3;
                aux1=0;
                aux2=1;
                for(int i=1;i<=V.maxsize-2;i++)
                {
                    aux3=aux1+aux2;
                    V+=aux3;
                    aux1 = aux2;
                    aux2 = aux3;
                }
             }
}

ostream& operator<<(ostream& out,Nr_Natural_Mare& n)
{

    out<<"Numarul pe care il cauti este: "<<n.V[n.nr_cif-1]<<endl;
    out<<"Iar descompunerea lui in suma de numere Fibonacci este: "<<n.V[n.nr_cif-3]<<" + "<<n.V[n.nr_cif-2]; // Varianta in care afisez cele 2 numere cale il preced si care adunate dau numarul

    /*
        out<<"Numarul pe care il cauti este: "<<n.V[n.nr_cif-1]<<endl;
        out<<"Iar descompunerea lui in suma de numere Fibonacci este: ";
        for(int i=0;i<n.nr_cif-1;i++)
        {
            out<<n.V[i];
            if(i != n.nr_cif-2)
                out<<" + ";
        }
    */
    return out;
}

void Nr_Natural_Mare::Print(Nr_Natural_Mare& n)
{
    cout<<n;
}

// Functiile clasei Nr_Fibonacci_mare

void Nr_Fibonacci_mare::Fib()
{
    if(V.maxsize == 0)
        throw "Nope!";
    else
        if(V.maxsize == 1)
            {V+=0; throw "Numarul este: 0, iar descompunerea este: 0";}//cout<<"Numarul este: 0"<<endl<<"iar descompunerea este: 0";}
        else
            if(V.maxsize == 2)
            {
                V+=0;
                V+=1;
                throw "Numarul este: 1, iar descompunerea este: 0 + 1";
                //cout<<"Numarul este: 1"<<endl<<"Iar descompunerea lui este: 0 + 1";
            }
            else
             {
                V+=0;
                V+=1;
                int aux1,aux2,aux3;
                aux1=0;
                aux2=1;
                for(int i=1;i<=V.maxsize-2;i++)
                {
                    aux3=aux1+aux2;
                    V+=aux3;
                    aux1 = aux2;
                    aux2 = aux3;
                }
             }
}

void Nr_Fibonacci_mare::Print(Nr_Fibonacci_mare& n)
{
    cout<<n;
}

int main()
{

    Nr_Natural_Mare* n =new Nr_Fibonacci_mare();

    n->Fib();
    n->Print(*n);
    return 0;
}
