#pragma once
#include "Address.h"
#include <string>

class Delivery {
public:
    Delivery(int id, const Address& address, const std::string& status);
    void updateStatus(const std::string& status);

private:
    int id;
    Address address;
    std::string status;
};
