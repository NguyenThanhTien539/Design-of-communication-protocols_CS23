#pragma once
#include <string>


class Response{
private:
    int status_code;
    std::string status_test;
public:
    Response(){}
    Response(int code, std::string test) : status_code(code), status_test(test){}
    static Response unauthorized();
    static Response error();
    std::string toCS23Format() const;
};