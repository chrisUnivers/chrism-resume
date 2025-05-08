#include "PureBlock.h"
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"

class DiamondBlock : public PureBlock
{
public:
    DiamondBlock();
    DiamondBlock (int world_id);
    void setPosition(double x, double y, double z);
    std::vector<double> getPosition();
    std::pair<std::string, double> getBreakTool();
private:
    int WorldId_{0};
    
};

// BlockId_ BlockName_ BlockTexture_ BlockType_