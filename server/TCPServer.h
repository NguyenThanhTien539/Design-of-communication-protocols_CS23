#pragma once
#include "core/Response.h"
#include "core/Request.h"
#include "RequestParser.h"
#include "AuthMiddleware.h"
#include "core/TokenStore.h"

class TCPServer{
private:
    int port;
public:
    TCPServer(int p) : port(p){}
    void run();
};