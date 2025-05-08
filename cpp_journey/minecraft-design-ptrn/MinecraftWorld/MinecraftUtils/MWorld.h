#ifndef M_WORLD_H
#define M_WORLD_H

#include <memory>
#include <vector>

class MWorld {
public:
    MWorld() {}
    virtual ~MWorld() = default;

    virtual void createMWorld() = 0;
private:
    std::unique_ptr<std::vector<int>> worldBlockIds_;
    std::unique_ptr<std::vector<MinecraftBiomes>> worldBiomes_;
};

#endif