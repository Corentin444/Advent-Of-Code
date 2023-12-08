#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>

#include "../utils.h"

using namespace std;

int main()
{
    int sum = 0;
    int lineId = 1;
    bool possible;
    map<string, int> colors = {{"r", 12}, {"g", 13}, {"b", 14}};
    for(string line : readLines("input.txt"))
    {
        possible = true;
        for (string s : getRegexMatches(line, "([0-9]+\\sr)|([0-9]+\\sg)|([0-9]+\\sb)"))
        {
            int n = stoi(s.substr(0, s.size() - 2));
            string color = s.substr(s.size() - 1);
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

    cout << sum;
}