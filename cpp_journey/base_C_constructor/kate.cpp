#include <iostream>
#include <string>
#include "base_C_construct.h"
#include "drvd_c_construct.h"
#include "snd_base_class.h"

int main()
{
    Child lily(98, "while");
    // Father Ken;
    lily.display();
    std::cout << "back to main" << std::endl;
    return 0;
}