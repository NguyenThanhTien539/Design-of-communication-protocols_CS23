#include "StringUtils.h"
#include <iostream>

std::string StringUtils::trim(std::string s)
{
   size_t start_pos = s.find_first_not_of(" \t\n\r\"");
   size_t end_pos = s.find_last_not_of(" \t\n\r\"");

   return (start_pos == std::string::npos) ? "" : s.substr(start_pos, (end_pos - start_pos + 1));
}

std::vector<std::string> StringUtils::split(const std::string &s, char delimiter)
{
   std::vector<std::string> tokens;
   std::stringstream ss(s);
   std::string item;
   while(std::getline(ss, item, delimiter)){
      tokens.push_back(item);
   }
   return tokens;
}

std::map<std::string, std::string> StringUtils::parseJson(const std::string &bodyJson)
{
   std::cout<< bodyJson <<'\n';
   std::map<std::string, std::string> body;
   std::vector<std::string> tokens = split(bodyJson, ',');
   if(bodyJson.empty() || bodyJson.front() != '{' || bodyJson.back() != '}')
      throw std::invalid_argument("Invalid Json Format");

   std::string inner = bodyJson.substr(1, bodyJson.size() - 2);
   std::cout << inner <<'\n';
   std::string line;
   std::stringstream ss(inner);
   while(std::getline(ss, line, ',')){
      size_t colon = line.find(':');
      if(colon == std::string::npos){
         continue;
      }
      std::string key = line.substr(0, colon);
      std::string value = line.substr(colon + 1);

      key = trim(key);
      value = trim(value);
      body[key] = value;
   }
   return body;
}
