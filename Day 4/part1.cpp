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
    int lineId = 0;

    for (std::string line : readLines("input.txt"))
    {
        std::string numbers = split(split(line, ": ")[1], "|")[0];
        numbers = numbers.substr(1, numbers.size() - 2);
        std::string winnings = split(split(line, ": ")[1], "|")[1];
        std::vector<int> numbersI = {};
        std::vector<int> winningsI = {};
        double a = 0.5;
        for(std::string number : split(numbers, " "))
        {
            if (number != "" && number != " ")
                numbersI.push_back(stoi(number));
        }
        for(std::string winning : split(winnings, " "))
        {
            if (winning != "" && winning != " ")
                winningsI.push_back(stoi(winning));
        }
        
        for(int n : numbersI)
        {
            if ( std::find(winningsI.begin(), winningsI.end(), n) != winningsI.end() )
            {
                a = a * 2;
            }
        }

        if(a > 0.5)
        {
            ans += a;
        }
        lineId++;
    }

    std::cout << ans;
}