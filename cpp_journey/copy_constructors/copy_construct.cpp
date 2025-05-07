#include <iostream>
#include <string>
#include "copy_construct.h"

Person::Person(int iage, std::string iname)
{
    age = iage;
    Gname = new std::string(iname);
}

Person::Person(const Person &p) // The copy construct is invoked when: Person duplicateP = lillie--lillie of type Person
{
    Gname = new std::string(*p.Gname);
    // Not initializing the age could result in age having garbage values if original obj did not init age.
    age = p.age;
}

void Person::changeNameAndAge(std::string name, int age)
{
    *(this->Gname) = name;
    this->age = age;
}

void Person::introduce()
{
    std::cout << "Hey, I am " << *Gname << " and I am " << age << "years old" << std::endl;
}