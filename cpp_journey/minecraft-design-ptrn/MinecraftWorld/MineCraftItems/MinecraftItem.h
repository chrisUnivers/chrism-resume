#ifndef MINECRAFT_ITEM_H
#define MINECRAFT_ITEM_H


#include "PureItem.h"

class MinecraftItem {
public:
    MinecraftItem() {}
    virtual ~MinecraftItem() = default;
    virtual PureItem SpawnItem() = 0;
};

#endif