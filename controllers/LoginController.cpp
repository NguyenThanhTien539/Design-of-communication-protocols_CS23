#include "LoginController.h"
#include "utils/TokenGenerator.h"
#include <string>
#include "core/TokenStore.h"
#include <iostream>
Response LoginController::handle(const Request &req)
{
    auto json = req.body;
    std::string username = json["username"];
    std::string password = json["password"];



    if (username == "admin" && password == "123456")
    {
        std::string token = TokenGenerator::generate();
        TokenStore::instance().store(token, Role::ADMIN);
        return {200, token};
    }
    else if (username == "user" && password == "123456")
    {
        std::string token = TokenGenerator::generate();
        TokenStore::instance().store(token, Role::USER);
        return {200, token};
    }
    return {200, "Fail login!!!"};
}