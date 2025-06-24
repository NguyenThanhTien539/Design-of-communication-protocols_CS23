#include "Controllers.h"


class LoginController : public Controller{
public:
    Response handle(const Request &req) override;
};