#ifndef TREE_H
#define TREE_H

#include "PureTree.h"

class Tree {
public:
    virtual ~Tree() = default;
    virtual void CreateTree(std::string tree_name, std::unique_ptr<PureTree> &tree) const = 0;
};

#endif