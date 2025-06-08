#include "Router.h"
#include "controllers/LoginController.h"
#include "controllers/AdminController.h"
#include "controllers/UserController.h"
#include "core/TokenStore.h"
Controller *Router::getController(const Request &req)
{


    if (req.path == "/login" && req.method == "POST")
    {
        return new LoginController();
    }

    if(req.path == "/admin" && req.method == "GET" && TokenStore::instance().getRole(req.token) == Role::ADMIN)
    {

        return new AdminController();
    }

    if(req.path == "/user" && req.method == "GET"&& TokenStore::instance().getRole(req.token) == Role::USER)
    {
        return new UserController();
    }
    // TODO
    return nullptr;
}
