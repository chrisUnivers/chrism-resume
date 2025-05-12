#ifndef DIAMOND_APPLE_H
#define DIAMOND_APPLE_H

#include "../MineCraftFood/MinecraftApple.h"

class DiamondApple : public MinecraftApple {
public:
    DiamondApple();
    ~DiamondApple() = default;
    void setPosition(std::unique_ptr<ItemPosition> item_pos) const override;
    ItemPosition* getPosition() const override;
    
protected:
    FoodEffect foodEffect_;
};

#endif