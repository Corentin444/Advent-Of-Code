#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <algorithm>
#include <utility>

#include "../utils.h"

using namespace std;

int main()
{
    int size = 204;
    int ans = 0;
    int lineId = 0;
    vector<int> copies;
    for (size_t i = 0; i < size; i++)
    {
        copies.push_back(1);
    }

    for (string line : readLines("input.txt"))
    {
        line = splitByString(line, ": ")[1];
        string numbersS = splitByString(line, "|")[0];
        string winningsS = splitByString(line, "|")[1];
        vector<int> numbersV = {};
        vector<int> winningsV = {};

        for (string numberS : getRegexMatches(numbersS, "\\d+"))
        {
            numbersV.push_back(stoi(numberS));
        }

        for (string winningS : getRegexMatches(winningsS, "\\d+"))
        {
            winningsV.push_back(stoi(winningS));
        }

        int winningNumbers = 0;

        for (int number : numbersV)
        {
            if (contains(winningsV, number))
            {
                winningNumbers++;
            }
        }

        for (size_t i = lineId + 1; i < lineId + winningNumbers + 1; i++)
        {
            if (i < size)
            {
                copies[i] += copies[lineId];
            }
        }

        lineId++;
    }
    for (size_t i = 0; i < copies.size(); i++)
    {
        ans += copies[i];
    }

    cout << ans;
}