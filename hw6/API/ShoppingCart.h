#pragma once
#include "MenuItem.h"
#include "Order.h"
#include <vector>

class ShoppingCart {
public:
    void addItem(const MenuItem& item);
    void removeItem(const MenuItem& item);
    Order checkout();

private:
    std::vector<MenuItem> items;
};
