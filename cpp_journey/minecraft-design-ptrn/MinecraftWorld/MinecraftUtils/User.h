#ifndef USER_H
#define USER_H

#include <string>
#include <memory>
#include "MinecraftItem.h"
#include <vector>

class User {
public:
    User(std::string name, int userid);
private:
    std::string name_{""};
    int userId_{0};
    std::unique_ptr<std::vector<std::unique_ptr<MinecraftItem>>> userItems_;
};

#endif