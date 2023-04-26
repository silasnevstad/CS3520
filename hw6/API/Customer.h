#pragma once
#include "User.h"
#include "MenuItem.h"
#include "Order.h"
#include "ShoppingCart.h"
#include <vector>

class Customer : public User {
public:
    Customer(int id, const std::string& username, const std::string& password, const std::string& email);
    void placeOrder(const Order& order);
    std::vector<Order> viewOrderHistory() const;

private:
    std::vector<MenuItem> favoriteItems;
    std::vector<Order> orders;
    ShoppingCart shoppingCart;
};
