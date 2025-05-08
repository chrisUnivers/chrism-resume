#ifndef PURE_BLOCK_H
#define PURE_BLOCK_H

#include <string>
#include <vector>

#include "../Utils/ItemNames.h"

class PureBlock {
protected:
    int          BlockId_;
    BlockName    BlockName_;
    BlockTexture BlockTexture_;
    std::string  BlockType_;
public:
    PureBlock() {}
    virtual ~PureBlock() = default;
    virtual void setPosition(double x, double y, double z) = 0;
    virtual std::vector<double> getPosition() = 0;
    /// @brief Returns the tool that best breaks a block type
    /// @return break_tool_pair<std::string tool_name, double break_multiple>
    virtual std::pair<std::string, double> getBreakTool() = 0;
};

#endif