#pragma once
#include "core/TokenStore.h"
#include "core/Request.h"


class AuthMiddleware{
public:
    static bool authorize(const Request& req);
};