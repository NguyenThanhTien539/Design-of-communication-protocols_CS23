#include "AuthMiddleware.h"

bool AuthMiddleware::authorize(const Request &req)
{
    std::string path = req.path;
    if(path == "/login")
        return true;
    
    return TokenStore::instance().containToken(req.token);
}