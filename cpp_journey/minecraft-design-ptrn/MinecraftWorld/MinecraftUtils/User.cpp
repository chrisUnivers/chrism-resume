
#include "User.h"

User::User(std::string name, int userId) : name_{name}, userId_{userId} {
    userItems_->emplace_back(std::make_unique<MinecraftItem>());
}