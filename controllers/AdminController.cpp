#include "AdminController.h"


Response AdminController::handle(const Request& req){
    return {200, "Hello NTT"};
}