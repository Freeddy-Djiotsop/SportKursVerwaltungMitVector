#include <iostream>
#include<vector>
#include <iomanip>
#include "sportkurs.hpp"
#include "person.hpp"



using namespace std;

float Sportkurs::durchschnitt() const
{
    float s=0;

    if(this->teilnehmer)
    {
        for(unsigned int i=0; i<this->teilnehmer; i++)
            s += this->person[i].alter;

        s /=this->teilnehmer;
    }

    return s;
}

Sportkurs::Sportkurs(std::string n, std::string m , unsigned int i)
:kName(n), tName(m), maxteilnehmer(i){}

Sportkurs::Sportkurs(const Sportkurs& k)//Copy-Konstruktor
:kName(k.kName), tName(k.tName), maxteilnehmer(k.maxteilnehmer), teilnehmer(k.teilnehmer)
{
    for(auto i=k.person.begin(); i!=k.person.end(); i++)
        this->person.push_back(*i);
}

Sportkurs::Sportkurs(Sportkurs&& k)//Move-Konstruktor
:kName(k.kName), tName(k.tName), maxteilnehmer(k.maxteilnehmer), teilnehmer(k.teilnehmer)
//alle Daten mit Initialisiererliste belegen
{
    for(auto i=k.person.begin(); i!=k.person.end(); i++)
        this->person.push_back(*i);

    //Daten Löschen der temporaere Objekt;
    k.maxteilnehmer = 0;
    k.teilnehmer = 0;
    k.person.clear();
}

Sportkurs::~Sportkurs(){person.clear();}



void Sportkurs::operator=(const Sportkurs& k)
{
    if(this!=&k)
    {
        this->kName = k.kName;
        this->tName = k.tName;
        this->maxteilnehmer = k.maxteilnehmer;
        this->teilnehmer = k.teilnehmer;

        this->person.clear();

        for(unsigned int i=0; i<this->teilnehmer; i++)//Kopie erstellen
            this->person.push_back(k.person[i]);
    }
}

void Sportkurs::operator=(Sportkurs&& k)
{
    this->kName = k.kName;
    this->tName = k.tName;
    this->maxteilnehmer = k.maxteilnehmer;
    this->teilnehmer = k.teilnehmer;

    this->person.clear();//Speicherplatz freigeben

    for(auto i=k.person.begin(); i!=k.person.end(); i++)
        this->person.push_back(*i);//neue Daten bzw Speicherplatz

    //Daten Löschen der temporaere Objekt;
    k.maxteilnehmer = 0;
    k.teilnehmer = 0;
    k.person.clear();
}

void Sportkurs::addPerson(const Person& p)
{
    if(teilnehmer+1>maxteilnehmer)
        cout<<"Der Sportkurs "<<this->kName<<" ist voll"<<endl;

    else
    {
        this->teilnehmer++;
        person.push_back(Person(p.name, p.geschlecht, p.alter));
    }
}

void vergleicheTeilnehmer(const Sportkurs& a, const Sportkurs& b)
{
    if(a.teilnehmer>b.teilnehmer)
        cout<<a.kName<<" hat mehr teilnehmer"<<endl;
    else if (a.teilnehmer<b.teilnehmer)
        cout<<b.kName<<" hat mehr teilnehmer"<<endl;
    else//wenn a nicht > b oder nicht < b, dann ist a=b
        cout<<a.kName<<" und "<<b.kName<<" haben gleiche Anzahl Teilnehmer"<<endl;
}

ostream& operator<<(ostream& os, const Sportkurs& k)
{
    os<<k.kName<<", "<<k.tName<<", "<<k.maxteilnehmer<<", "<<k.teilnehmer;
    os<<", Altersschnitt: "<<setprecision(3)<<k.durchschnitt()<<endl;

    if(k.person.empty())
        return os;

    for(auto i = k.person.begin(); i!=k.person.end(); i++)
        os<<*i<<endl;
    os<<endl;

    return os;
}

istream& operator>>(istream& is, Sportkurs& k)
{
    is>>k.kName>>k.tName>>k.maxteilnehmer;
    return is;
}
