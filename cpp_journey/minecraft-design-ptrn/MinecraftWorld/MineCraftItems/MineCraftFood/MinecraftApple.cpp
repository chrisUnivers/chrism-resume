#include "MinecraftApple.h"


MinecraftApple::MinecraftApple() : MinecraftApple::MinecraftApple(FOOD_TYPE, DEFAULT_MAKE) {
}

MinecraftApple::MinecraftApple(ItemTypes item_type, ItemMake item_make) {
    itemType_ = item_type;
    itemMake_ = item_make;
}

// void MinecraftApple::setPosition(std::unique_ptr<ItemPosition> item_pos) const {
//     itemPosition_ = item_pos;
// }

// ItemPosition* getPosition()