#ifndef SPORTKURS_HPP_INCLUDED
#define SPORTKURS_HPP_INCLUDED


class Person;

class Sportkurs
{

private:
    std::string kName;
    std::string tName;
    unsigned int teilnehmer=0;
    unsigned int maxteilnehmer;
    std::vector<Person> person;

    float durchschnitt() const;

public:
    Sportkurs():teilnehmer(0){}
    Sportkurs(std::string, std::string, unsigned int);
    ~Sportkurs();
    Sportkurs(const Sportkurs&);
    Sportkurs(Sportkurs&&);

    void operator=(const Sportkurs&);
    void operator=(Sportkurs&&);
    void addPerson(const Person&);


    friend std::ostream& operator<<(std::ostream&, const Sportkurs&);
    friend std::istream& operator>>(std::istream&, Sportkurs&);
    friend void vergleicheTeilnehmer(const Sportkurs&, const Sportkurs&);

};

#endif // SPORTKURS_HPP_INCLUDED
