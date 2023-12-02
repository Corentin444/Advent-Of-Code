#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>

#include "../utils.h"

int main()
{
    int sum = 0;
    int lineId = 1;
    bool possible;
    std::map<std::string, int> colors = {{"r", 12}, {"g", 13}, {"b", 14}};
    for(std::string line : readLines("input.txt"))
    {
        possible = true;
        std::regex word_regex("([0-9]+\\sr)|([0-9]+\\sg)|([0-9]+\\sb)");
        for (std::string s : split(line, word_regex))
        {
            int n = std::stoi(s.substr(0, s.size() - 2));
            std::string color = s.substr(s.size() - 1);
            if(n > colors[color])
            {
                possible = false;
                break;
            }
        }

        if(possible)
        {
            sum += lineId;
        }
        lineId++;
    }

    std::cout << sum;
}