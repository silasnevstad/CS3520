#pragma once
#include "MenuItem.h"
#include <vector>

class Menu {
public:
    void addItem(const MenuItem& item);
    void removeItem(const MenuItem& item);
    void updateItem(const MenuItem& item);

private:
    std::vector<MenuItem> items;
};
