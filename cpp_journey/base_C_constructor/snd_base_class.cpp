#include <iostream>
#include "snd_base_class.h"

Mother::Mother()
{
    std::cout << "constructor of mother is called" << std::endl;
}

void Mother::displayNode()
{
    Mother::tnode = "left";
    std::cout << "The node " << Mother::tnode << std::endl;
}