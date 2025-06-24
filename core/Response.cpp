#include "Response.h"

Response Response::unauthorized()
{
    return Response(403, "Forbidden");
}

Response Response::error()
{
    return Response(500, "Internal Server Error");
}

std::string Response::toCS23Format() const
{
    std::string s = status_code + " " + status_test;
    return s;
}
