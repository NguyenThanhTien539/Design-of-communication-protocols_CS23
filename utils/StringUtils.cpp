#include "StringUtils.h"
#include <string>
#include <iostream>
std::string StringUtils::trim(std::string s)
{
    // std::cout << s << '\n';
    int i = 0;
    int j = s.size() - 1;
    while (i <= j && (s[i] == ' ' || s[i] == '\n' || s[i] == '\r')) i++;
    while (j >= i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\r')) j--;
    if (i > j) return "";
    // std::cout << s;
    return s.substr(i, j - i + 1);
}


std::vector<std::string> StringUtils::split(const std::string &s, char delimiter)
{
    std::vector<std::string> res;
    size_t start = 0;
    size_t pos;

    while ((pos = s.find(delimiter, start)) != std::string::npos)
    {
        res.push_back(s.substr(start, pos - start));
        start = pos + 1;
    }

    res.push_back(s.substr(start));

    return res;
}


std::map<std::string, std::string> StringUtils:: parseJSON(const std::string &json)
{
    std::map<std::string, std::string> res;
    std::string s = json;
    s = trim(s);
    if (s[0] == '{') {
        s = s.erase(0, 1);
    }
    
    if(s[s.size() - 1] == '}')
    s = s.erase(s.size() - 1 , 1);
    
    std::cout << s << '\n';
    std::vector<std::string> pairs = split(s, ',');
    // std::cout << pairs[0] << 'f' << pairs[1] <<'\n';
    for (auto &pair : pairs) {
        auto kv = split(pair, ':');
        if (kv.size() != 2) continue;

        std::string key = trim(kv[0]);
        std::string value = trim(kv[1]);

        if (!key.empty() && key.front() == '"' && key.back() == '"') {
            key = key.substr(1, key.size() - 2);
        }
        if (!value.empty() && value.front() == '"' && value.back() == '"') {
            value = value.substr(1, value.size() - 2);
        }
        res[key] = value;
    }


    
    return res;
}

