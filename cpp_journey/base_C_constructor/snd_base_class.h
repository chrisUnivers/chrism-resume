#ifndef SND_BASE_CLASS_H
#define SND_BASE_CLASS_H

#include <iostream>
#include <string>

class Mother
{
protected:
    std::string skincolor;
    std::string tnode;
public:
    Mother();
    void displayNode();
};

#endif // SND_BASE_CLASS_H

//Jan 25th 2023 ended here. Wanted to see if I have access to the private member node