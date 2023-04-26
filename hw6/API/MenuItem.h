#pragma once
#include <string>

class MenuItem {
public:
    MenuItem(int id, const std::string& name, const std::string& description, float price);

private:
    int id;
    std::string name;
    std::string description;
    float price;
};
