#pragma once
#include "Customer.h"
#include "MenuItem.h"
#include "Delivery.h"
#include "Payment.h"
#include <vector>

class Order {
public:
    Order(int id, const Customer& customer, const std::vector<MenuItem>& items, const Delivery& delivery, const Payment& payment);
    float calculateTotal() const;

private:
    int id;
    Customer customer;
    std::vector<MenuItem> items;
    Delivery delivery;
    Payment payment;
};
