#include <iostream>
#include <string>
#include "base_C_construct.h"
#include "drvd_c_construct.h"

Child::Child(int x) : Father(x), Mother()
{
    std::cout << "Child class constructor" << std::endl;
}
Child::Child(int y, std::string color) : Father(), Mother()
{
    height = y;
    skincolor = color;
    std::cout << "Child class constructor." << std::endl;
}
void Child::display()
{
    std::cout << "height is: " << height << " skin color is: " << skincolor<<std::endl;
}
