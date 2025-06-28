#pragma once
#include "core/Request.h"
#include "controllers/Controllers.h"
class Router{
public:
    static Controller *getController(const Request &req);
};
