#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <algorithm>
#include <utility>

#include "../utils.h"

int main()
{
    int ans = 0;

    for (std::string line : readLines("input.txt"))
    {
        line = splitByString(line, ": ")[1];
        std::string numbersS = splitByString(line, "|")[0];
        std::string winningsS = splitByString(line, "|")[1];
        std::vector<int> numbersV = {};
        std::vector<int> winningsV = {};

        for (std::string numberS : getRegexMatches(numbersS, "\\d+"))
        {
            numbersV.push_back(stoi(numberS));
        }

        for (std::string winningS : getRegexMatches(winningsS, "\\d+"))
        {
            winningsV.push_back(stoi(winningS));
        }

        double a = 0.5;
        for (int number : numbersV)
        {
            if (contains(winningsV, number))
            {
                a = a * 2;
            }
        }

        if (a > 0.5)
        {
            ans += a;
        }
    }

    std::cout << ans;
}