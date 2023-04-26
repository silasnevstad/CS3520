#pragma once
#include "User.h"
#include "Menu.h"
#include "Address.h"

class Restaurant : public User {
public:
    Restaurant(int id, const std::string& username, const std::string& password, const std::string& email, const std::string& name, const Address& address);
    void createMenu(const Menu& menu);
    void updateMenu(const Menu& menu);

private:
    std::string name;
    Address address;
    Menu menu;
};
