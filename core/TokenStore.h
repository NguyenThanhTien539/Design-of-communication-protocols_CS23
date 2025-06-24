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

    inline friend std::ostream &operator<<(std::ostream &os, const TokenStore& store );
};

inline std::ostream &operator<<(std::ostream &os, Role role);
