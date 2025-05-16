#include <memory>

#include "UniqueWorld.h"
#include "../Utils/defaults.h"
#include "WorldConstructors.h"
#include <iostream>



UniqueWorld::UniqueWorld(){
}

void UniqueWorld::CreateWorld(const std::string& world_name, std::unique_ptr<PureWorld>& world) const {
    
}