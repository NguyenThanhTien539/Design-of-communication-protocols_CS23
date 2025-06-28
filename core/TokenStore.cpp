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

bool TokenStore::containToken(const std::string &token)
{
    auto it = tokenRoleMap.find(token);
    if(it == tokenRoleMap.end())
        return false;
    return true;
}



