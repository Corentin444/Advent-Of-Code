#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <algorithm>

#include "../utils.h"

int main()
{
    int sum = 0;
    std::map<std::string, int> colors;
    for(std::string line : readLines("input.txt"))
    {
        colors = {{"r", -1}, {"g", -1}, {"b", -1}};
        for (std::string s : getRegexMatches(line, "([0-9]+\\sr)|([0-9]+\\sg)|([0-9]+\\sb)"))
        {
            int n = std::stoi(s.substr(0, s.size() - 2));
            std::string color = s.substr(s.size() - 1);
            colors[color] = std::max(n, colors[color]);
        }
        sum += colors["r"] * colors["g"] * colors["b"];
    }

    std::cout << sum;
}