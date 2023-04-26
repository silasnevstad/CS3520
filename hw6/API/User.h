#pragma once
#include <string>

class User {
public:
    User(int id, const std::string& username, const std::string& password, const std::string& email);
    bool authenticate(const std::string& password) const;

protected:
    int id;
    std::string username;
    std::string password;
    std::string email;
};
