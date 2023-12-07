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
    int ans = 1;

    std::vector<int> times;
    std::vector<int> distances;
    std::vector<std::string> lines = readLines("input.txt");
    for (std::string s : getRegexMatches(lines[0], "\\d+"))
    {
        times.push_back(std::stoi(s));
    }

    for (std::string s : getRegexMatches(lines[1], "\\d+"))
    {
        distances.push_back(std::stoi(s));
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
            std::cout << n << "\n";
            ans = ans * n;
        }
    }

    std::cout << ans;
}