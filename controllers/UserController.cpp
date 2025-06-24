#include "UserController.h"

Response handle(const Request& req){
    return{200, "Hello, user"};
}
