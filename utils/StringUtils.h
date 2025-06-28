#pragma once
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
class StringUtils{
public:
    static std::string trim(std::string s);
    static std::vector<std::string> split(const std::string &s, char delimiter);
    static std::map<std::string, std::string> parseJson(const std::string &bodyJson);
};