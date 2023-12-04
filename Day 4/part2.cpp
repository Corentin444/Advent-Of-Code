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
    int size = 204;
    int ans = 0;
    int lineId = 0;
    std::vector<int> copies;
    for (size_t i = 0; i < size; i++)
    {
        copies.push_back(1);
    }

    for (std::string line : readLines("input.txt"))
    {
        std::string numbers = split(split(line, ": ")[1], "|")[0];
        numbers = numbers.substr(1, numbers.size() - 2);
        std::string winnings = split(split(line, ": ")[1], "|")[1];
        std::vector<int> numbersI = {};
        std::vector<int> winningsI = {};
        int winningNumbers = 0;
        for (std::string number : split(numbers, " "))
        {
            if (number != "" && number != " ")
                numbersI.push_back(stoi(number));
        }
        for (std::string winning : split(winnings, " "))
        {
            if (winning != "" && winning != " ")
                winningsI.push_back(stoi(winning));
        }

        for (int n : numbersI)
        {
            if (std::find(winningsI.begin(), winningsI.end(), n) != winningsI.end())
            {
                winningNumbers++;
            }
        }

        for (size_t i = lineId + 1; i < lineId + winningNumbers + 1; i++)
        {
            if (i < size)
                copies[i] += copies[lineId];
        }

        lineId++;
    }
    for (size_t i = 0; i < copies.size(); i++)
    {
        ans += copies[i];
    }

    std::cout << ans;
}