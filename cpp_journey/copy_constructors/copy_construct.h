#ifndef COPY_CONSTRUCTOR_H
#define COPY_CONSTRUCTOR_H

#include <string>

class Person
{
public:
    int age;
    std::string name;
    std::string *Gname;
    
    Person(int iage, std::string iname);
    Person(const Person &p);
    void changeNameAndAge(std::string iname, int iage);
    void introduce();
};

#endif //COPY_CONSTRUCTOR_H