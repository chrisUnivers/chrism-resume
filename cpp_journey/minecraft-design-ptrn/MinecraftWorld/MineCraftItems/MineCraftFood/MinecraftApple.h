#ifndef MINECRAFT_APPLE_H
#define MINECRAFT_APPLE_H

#include "../PureItem.h"
#include "../../Utils/ItemStructs.h"

class MinecraftApple : public PureItem {
public:
    MinecraftApple();
    MinecraftApple(ItemTypes item_type, ItemMake item_make);
    
    virtual void setPosition(std::unique_ptr<ItemPosition> item_pos) const = 0;
    virtual ItemPosition* getPosition() const = 0;
};

#endif

/** Need getMethods for below since protected in PureItem.h;
 * itemId_
itemGenerated_
itemTexture_
itemType_
itemMake_
itemPosition_
 */