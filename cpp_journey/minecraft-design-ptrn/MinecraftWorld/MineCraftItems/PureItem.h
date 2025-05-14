#ifndef PURE_ITEM_H
#define PURE_ITEM_H

#include <string>
#include <vector>
#include <memory>

#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"

class PureItem {
protected:
    int           itemId_;      // random int generated
    SpawnItem     spawnItem_;  // generated, crafted, or drop(leaves or apples)
    ItemTypes     itemType_;
    ItemMake      itemMake_;
    std::unique_ptr<ItemPosition> itemPosition_; 
public:
    virtual ~PureItem() = default;
};

#endif

