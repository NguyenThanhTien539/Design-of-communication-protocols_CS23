#pragma once
#include "Controllers.h"


class UserController : public Controller{
public:
    Response handle(const Request& req) override;
};