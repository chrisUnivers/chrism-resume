#ifndef PURE_ITEM_H
#define PURE_ITEM_H

#include <string>
#include <vector>
#include <memory>

#include "../Utils/ItemNames.h"

class PureItem {
protected:
    int           itemId_; // random int generated
    bool          itemGenerated_ = false; // vs crafted item
    ItemTextures  itemTexture_; // Stone, Block, gravel
    ItemTypes     itemType_;
    ItemMake      itemMake_;
    std::unique_ptr<ItemPosition> itemPosition_; 
public:
    PureItem() {}
    virtual ~PureItem() = default;
};

#endif