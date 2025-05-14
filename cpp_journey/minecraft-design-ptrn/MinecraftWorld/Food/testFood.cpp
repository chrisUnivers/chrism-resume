#include <iostream>


#include "AppleFood.h"
#include <memory>


int main() { 
    std::unique_ptr<AppleFood> apple_food = std::make_unique<AppleFood>();
    std::unique_ptr<PureFood> food; 
    apple_food->CreateFood("apple", food);

    std::string new_food_name = food->getFoodItemName();    
    std::cout << "Food name is:: " << new_food_name << std::endl;
    std::cout << "Food needs a description!" << std::endl;
    return 0;
}