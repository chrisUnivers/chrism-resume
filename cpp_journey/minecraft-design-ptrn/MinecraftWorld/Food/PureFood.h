#ifndef PURE_FOOD_H
#define PURE_FOOD_H

#include <string>
#include <iostream>
#include <memory>
#include "../Utils/MineUtils.h"
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
class PureFood {
protected:
    int                           FoodId_;
    std::unique_ptr<FoodItem>     FoodItem_;
    std::unique_ptr<FoodEffect>   FoodEffect_;
public:
    virtual ~PureFood() = default;
    void getFood() { 
        std::cout << "I'am a food item: " << std::endl; 
    }
};

#endif