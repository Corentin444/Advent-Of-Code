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
    int ans = 1;

    vector<int> times;
    vector<int> distances;
    vector<string> lines = readLines("input.txt");
    for (string s : getRegexMatches(lines[0], "\\d+"))
    {
        times.push_back(stoi(s));
    }

    for (string s : getRegexMatches(lines[1], "\\d+"))
    {
        distances.push_back(stoi(s));
    }

    // Pour chaque course
    for (size_t race = 0; race < times.size(); race++)
    {
        int n = 0;
        // Pour chaque duree
        for (size_t time = 0; time < times[race]; time++)
        {
            int distance = time * (times[race] - time);
            if (distance > distances[race])
            {
                n++;
            }
        }
        if (n > 0)
        {
            cout << n << "\n";
            ans = ans * n;
        }
    }

    cout << ans;
}