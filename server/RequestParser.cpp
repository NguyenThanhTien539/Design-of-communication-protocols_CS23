#include "RequestParser.h"
#include <regex>
#include <iostream>
Request RequestParser::parse(const std::string &rawInput)
{
    Request req;

    std::istringstream iss(rawInput);
    if (!(iss >> req.method >> req.path >> req.token))
    {
        throw std::invalid_argument("Invalid input format (missing method/path/token)");
    }

   std::string line, bodyJson;
    while (std::getline(iss, line)) {
        bodyJson += line;
    }



    if (!bodyJson.empty())
    {
        req.body = StringUtils::parseJSON(bodyJson);

    }

    return req;
}

