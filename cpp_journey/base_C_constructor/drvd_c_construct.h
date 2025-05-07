#ifndef DRVD_C_CONSTRUCT_H
#define DRVD_C_CONSTRUCT_H

#include <iostream>
#include "base_C_construct.h"
#include "snd_base_class.h"


class Child : public Father, public Mother
{
public:
    Child (int x);
    Child (int y, std::string skincolor);
    void display();
};

#endif // DRVD_CONSTRUCT_H