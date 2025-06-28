#include "RequestParser.h"
#include <sstream>

Request RequestParser::parse(const std::string &rawInput)
{
    Request req;
    std::istringstream iss(rawInput);

    if(!(iss >> req.method >> req.path >> req.token )){
        throw std::invalid_argument("Invalid input format");
    }

    std::string line, bodyJson;
    while(getline(iss, line)){
        bodyJson += line;
    }

    if(!bodyJson.empty()){
        req.body = StringUtils::parseJson(StringUtils::trim(bodyJson));
    }

    return req;
}