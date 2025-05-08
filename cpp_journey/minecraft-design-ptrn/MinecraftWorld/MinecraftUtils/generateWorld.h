#ifndef GENERATE_WORLD_H
#define GENERATE_WORLD_H

#include <memory>
#include <vector>

constexpr int32_t TOTAL_NUMBER_OF_DIAMONDS = 10;

class MineCraftWorld
{
public:
    MineCraftWorld() {};
    void generateDiamonds();
    int randId();

private:
    std::unique_ptr<std::vector<int>> worldBlockIds_;
};

#endif