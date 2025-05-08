#include "DiamondBlock.h"
// #include "../Utils/ItemNames.h"

DiamondBlock::DiamondBlock(int world_id) : WorldId_{world_id} {
    BlockName_ = DIAMOND;
    BlockType_ = DIAMOND_STONE;
    BlockTexture_ = DIAMOND_TEXTURE;
}

// BlockId_ BlockName_ BlockTexture_ BlockType_