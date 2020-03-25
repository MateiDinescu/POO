#include <bits/stdc++.h>


using namespace std;

class Nod{
    friend class ListaCirculara;
private:
    int key;
    Nod *next;
public:
    Nod(){
        key=0;
        next=NULL;
    }
    void setkey(int key){this->key=key;}
    int getkey(){return key;}
    Nod(int k){
        key=k;
    }

};

class ListaCirculara{
private:
    Nod *cap;
public:

    ListaCirculara(){
        cap=NULL;
    }
    Nod * nodCheck(int k)
    {
        Nod *temp=NULL;
        Nod *ptr=cap;
        if(ptr==NULL)
        {
            return temp;
        }
        else
        {
            do{
                if(ptr->key==k)
                    temp=ptr;
            ptr=ptr->next;
            }while(ptr!=cap);
            return temp;
        }
    }

    void append(Nod * n)
    {
        if(nodCheck(n->key)!=NULL)
            cout<<"Nodul exista"<<endl;
        else
        {
            if(cap==NULL)
            {
                cap=n;
                n->next=cap;
                cout<<"Nodul a fost adaugat pe prima pozitie"<<endl;
            }
            else
            {
                Nod *ptr=cap;
                while(ptr->next!=cap)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->next=cap;
                cout<<"Nodul a fost adaugat"<<endl;
            }
        }
    }
    void inserareNod(int k,Nod *n)
    {
        Nod *ptr=nodCheck(k);
        if(ptr==NULL)
            cout<<"Nu exista niciun nod cu aceasta cheie"<<endl;
        else
        {
            if(nodCheck(n->key)!=NULL)
                cout<<"Exista un nod cu aceasta cheie"<<endl;
            else
            {
                if(ptr->next==cap)
                {
                    n->next=cap;
                    ptr->next=n;
                    cout<<"Nodul a fost inserat la sfarsit"<<endl;
                }
                else
                {
                    n->next=ptr->next;
                    ptr->next=n;
                    cout<<"Nodul a fost inserat"<<endl;
                }
            }
        }
    }

    void stergereNod(int k)
    {
        Nod *ptr=nodCheck(k);
        if(ptr==NULL)
            cout<<"Nu exista niciun nod cu aceasta cheie"<<endl;
        else
        {
            if(ptr==cap)
            {
                if(cap->next==NULL)
                {
                    cap==NULL;
                    cout<<"Nodul prim a fost sters, lista este goala"<<endl;
                }
                else
                {
                    Nod *ptr1=cap;
                    while(ptr1->next!=cap)
                        ptr1=ptr1->next;
                    ptr1->next=cap->next;
                    cap=cap->next;
                    cout<<"Nodul "<<k<<" a fost sters"<<endl;
                }
            }
            else
            {
                Nod *temp=NULL;
                Nod *prevptr=cap;
                Nod *curptr=cap->next;
                while(curptr!=NULL)
                {
                    if(curptr->key==k)
                    {
                        temp=curptr;
                        curptr=NULL;
                    }
                    else
                    {
                        prevptr=prevptr->next;
                        curptr=curptr->next;
                    }
                }
                prevptr->next=temp->next;
                cout<<"Nodul "<<k<<" a fost sters"<<endl;
            }
        }
    }

    void afisare()
    {
        if(cap==NULL)
            cout<<"Lista este goala";
        else
        {
            Nod *temp=cap;
            cout<<"{";
            do{
                cout<<temp->key<<" ";
                temp=temp->next;
            }while(temp!=cap);
            cout<<"}"<<endl;
        }
    }

    friend istream & operator>>(istream &,ListaCirculara&);
};

istream &operator >>(istream& in,ListaCirculara& l) //La citire nu se introduc valori, se introduce numarul de noduri din lista.
{
    int i;
    in>>i;
    for(unsigned j=1;j<=i;j++)
    {
        Nod *n=new Nod();
        n->setkey(j);
        l.append(n);
    }
    return in;
}


int main()
{
    ListaCirculara ob;
    Nod *n1=new Nod();
    ob.append(n1);
    Nod *n2=new Nod();
    n2->setkey(2);
    ob.append(n2);
    cout<<endl;
    ob.afisare();
    Nod *n3=new Nod();
    n3->setkey(3);
    ob.append(n3);
    Nod *n4=new Nod();
    n4->setkey(4);
    ob.inserareNod(n2->getkey(),n4);
    ob.afisare();
    Nod *n5=new Nod();
    n5->setkey(5);
    ob.append(n5);
    ob.afisare();
    ob.stergereNod(n3->getkey());
    ob.afisare();
    ListaCirculara test;
    cin>>test;
    test.afisare();
    return 0;
}
