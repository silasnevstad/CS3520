#pragma once
#include <string>

class Payment {
public:
    Payment(int id, float amount, const std::string& status);
    void processPayment();

private:
    int id;
    float amount;
    std::string status;
};
