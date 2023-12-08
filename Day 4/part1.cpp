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
    int ans = 0;

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

    cout << ans;
}