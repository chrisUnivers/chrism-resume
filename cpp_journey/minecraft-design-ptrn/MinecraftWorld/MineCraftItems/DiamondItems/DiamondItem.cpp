#include "DiamondItem.h"
// #include "../Utils/ItemNames.h"

DiamondItem::DiamondItem(int world_id) : WorldId_{world_id} {
    BlockName_ = DIAMOND;
    BlockType_ = DIAMOND_STONE;
    BlockTexture_ = DIAMOND_TEXTURE;
}

PureItem DiamondItem::SpawnItem() {
    
}

// BlockId_ BlockName_ BlockTexture_ BlockType_