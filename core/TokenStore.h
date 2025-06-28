#pragma once
#include <map>
#include <string>
#include <iostream>

enum class Role{
    ADMIN, 
    USER, 
    UNKNOWN,
};

class TokenStore{
private:
    std::map<std::string, Role> tokenRoleMap;
    TokenStore() = default;
public:
    static TokenStore &instance();
    Role getRole(const std::string &token);
    void storeRole(const std::string &token, Role role);
    bool containToken(const std::string &token);
    
    friend std::ostream &operator<<(std::ostream &os, const TokenStore &store);
    

};

inline std::ostream &operator<<(std::ostream &os, Role role)
{
    switch (role)
    {
    case Role::USER:
        return os << "USER";
    case Role::ADMIN:
        return os << "ADMIN";
    default:
        return os   << "UNKNOWN";
    }
}

inline std::ostream &operator<<(std::ostream &os, const TokenStore &store)
{
    for (const auto &entry : store.tokenRoleMap)
    {
        os << entry.first << " => " << entry.second << '\n';
    }
    return os;
}
