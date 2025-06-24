#include "TokenStore.h"

TokenStore &TokenStore::instance()
{
    static TokenStore instance;
    return instance;
}


Role TokenStore::getRole(const std::string &token)
{
    auto it = tokenRoleMap.find(token);
    if(it == tokenRoleMap.end())
        return Role::UNKNOWN;
    return it->second;
}

void TokenStore::storeRole(const std::string &token, Role role)
{
    tokenRoleMap[token] = role;
}

inline std::ostream &operator<<(std::ostream &os, const TokenStore &store)
{
        
}

inline std::ostream &operator<<(std::ostream &os, Role role)
{
    switch(role){
        case Role::ADMIN:
            return os << "ADMIN";
        case Role::USER:
            return os << "USER";
        default:
            return os << "UNKNOWN";
    }
}
