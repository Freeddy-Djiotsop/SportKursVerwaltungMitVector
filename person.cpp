#include <iostream>
#include <iomanip>
#include "person.hpp"

using namespace std;


Person::Person(string n, string g, unsigned short int a)
:name(n), geschlecht(g), alter(a){}

void Person::operator=(const Person& p)
{
    if(this!=&p)
    {
        this->name = p.name;
        this->geschlecht = p.geschlecht;
        this->alter = p.alter;
    }
}



ostream& operator<<(ostream& os, const Person& p)
{
    os<<p.name<<", "<<p.geschlecht<<", Alter: "<<p.alter;
    return os;
}
