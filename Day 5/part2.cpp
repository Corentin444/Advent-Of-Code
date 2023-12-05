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
    long long ans = 0;
    std::vector<std::string> lines = readLines("input.txt");
    std::vector<std::pair<long long, long long>> oldRanges;
    std::vector<std::pair<long long, long long>> newRanges;
    std::vector<std::string> hhh = splitByString(splitByString(lines[0], ": ")[1], " ");
    for (int i = 1; i< hhh.size(); i+=2)
    {
        std::string s1 = hhh[i];
        std::string s2 = hhh[i+1];
        std::pair<long long, long long> n (std::stoll(s1), std::stoll(s1) + std::stoll(s2));
        ranges.push_back(n);
        done.push_back(false);
    }

    for (size_t i = 2; i < lines.size(); i++)
    {
        std::string line = lines[i];
        if (line == "")
        {
            continue;
        }

        if (line.find(":") != std::string::npos)
        {
            for (size_t i = 0; i < done.size(); i++)
            {
                done[i] = false;
            }
        }
        else
        {
            // ligne avec nombres
            long long destStart = std::stoll(splitByString(line, " ")[0]); // 10
            long long srcStart = std::stoll(splitByString(line, " ")[1]); // 25
            long long rangeLength = std::stoll(splitByString(line, " ")[2]); // 3
            for (size_t i = 0; i < ranges.size(); i++)
            {
                long long start = ranges[i].first; // 20 => 10
                long long end = ranges[i].second; // 30 => 13
                bool aa = done[i];
                if (!aa && start >= srcStart && end < srcStart + rangeLength)
                {
                    ranges[i].first = destStart;
                    ranges[i].second = destStart + rangeLength;
                    done[i] = true;
                }
            }
        }
    }

    long long min = ranges[0].first;
    for (size_t i = 0; i < ranges.size(); i++)
    {
        if (ranges[i].first < min)
        {
            min = ranges[i].first;
        }
    }
    std::cout << min;

}