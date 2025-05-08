#include <string>
#ifndef MINECRAFT_ITEM_H
#define MINECRAFT_ITEM_H


class MinecraftItem {
public:
    MinecraftItem() : itemName_{""}, itemId_{0} {}
    virtual ~MinecraftItem() = default;

    virtual void create_minecraft_item() = 0;
private:
    std::string itemName_;
    int itemId_;
};
#endif