#pragma once
#include "Controllers.h"

class AdminController : public Controller{
public:
    Response handle(const Request &req) override;
};