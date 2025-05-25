#ifndef MINECRAFT_TREE_H
#define MINECRAFT_TREE_H


#include "PureTree.h"

class MinecraftTree : public PureTree {
public:
    virtual ~MinecraftTree() = default;
    int initItemInfo() const override { return 0; };
};

#endif