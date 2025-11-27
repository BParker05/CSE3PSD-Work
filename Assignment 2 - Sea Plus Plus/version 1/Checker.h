#pragma once

#include <string>
#include <map>
#include <vector>

class Checker {
protected:
    std::map<std::string, std::vector<int>> rules;
public:
    virtual ~Checker() = default;
    std::map<std::string, std::vector<int>>& getRules();
};
