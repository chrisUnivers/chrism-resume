#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
#include "../MinecraftItem.h"

class DiamondItem : public MinecraftItem
{
public:
    DiamondItem();
    DiamondItem (int world_id);
    PureItem SpawnItem();
    void setPosition(double x, double y, double z);
    std::vector<double> getPosition();
    std::pair<std::string, double> getBreakTool();
private:
    int WorldId_{0};
};