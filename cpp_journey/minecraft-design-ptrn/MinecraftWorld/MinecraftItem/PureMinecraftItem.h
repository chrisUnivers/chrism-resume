#ifndef PURE_MINECRAFT_ITEM_H
#define PURE_MINECRAFT_ITEM_H

#include <string>
#include <iostream>
#include <memory>

#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
class   PureMinecraftItem {
protected:
    MinecraftItemInfo     ItemInfo_;

public:
    PureMinecraftItem() {};
    virtual ~PureMinecraftItem() = default;
};
#endif