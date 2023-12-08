#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <algorithm>

#include "../utils.h"

using namespace std;

int main()
{
    int sum = 0;
    map<string, int> colors;
    for(string line : readLines("input.txt"))
    {
        colors = {{"r", -1}, {"g", -1}, {"b", -1}};
        for (string s : getRegexMatches(line, "([0-9]+\\sr)|([0-9]+\\sg)|([0-9]+\\sb)"))
        {
            int n = stoi(s.substr(0, s.size() - 2));
            string color = s.substr(s.size() - 1);
            colors[color] = max(n, colors[color]);
        }
        sum += colors["r"] * colors["g"] * colors["b"];
    }

    cout << sum;
}