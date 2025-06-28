#pragma once
#include "core/Response.h"
#include "core/Request.h"


class Controller{
public:
    virtual Response handle(const Request &req) = 0;
    virtual ~Controller() = default;
};