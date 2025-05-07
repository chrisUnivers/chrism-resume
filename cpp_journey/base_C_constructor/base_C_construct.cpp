#include <iostream>
#include "base_C_construct.h"


Father::Father()
{
    std::cout << "default constructor of father is called" << std::endl;
}
Father::Father(int h)
{
    std::cout << "constructor of father is called" << std::endl;
    height = h;
}
