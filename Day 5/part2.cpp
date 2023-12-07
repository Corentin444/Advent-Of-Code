#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <algorithm>
#include <utility>

#include "../utils.h"

std::vector<long long> remap(long long first, long long last, std::vector<std::vector<long long>> map)
{
    std::vector<long long> res;
    for (size_t i = 0; i < map.size(); i++)
    {
        long long destination = map[i][0];
        long long source = map[i][0];
        long long length = map[i][0];
        long long end = source + length - 1;
        long long distance = destination - source;

        if()
    }
    
}

int main()
{
    long long ans = 0;
    std::vector<std::string> lines = readLines("input.txt");
    std::vector<std::pair<long long, long long>> intervals;
    std::vector<std::string> firstLine = splitByString(splitByString(lines[0], ": ")[1], " ");
    for (int i = 1; i < firstLine.size(); i += 2)
    {
        long long start = std::stoll(firstLine[i]);
        long long end = start + std::stoll(firstLine[i + 1]) - 1;
        std::pair<long long, long long> interval(start, end);
        intervals.push_back(interval);
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
            long long destStart = std::stoll(splitByString(line, " ")[0]);   // 10
            long long srcStart = std::stoll(splitByString(line, " ")[1]);    // 25
            long long rangeLength = std::stoll(splitByString(line, " ")[2]); // 3
            std::pair<long long, long long> interval2(srcStart, srcStart + rangeLength - 1);

            for (std::pair<long long, long long> interval1 : intervals)
            {
                // si les deux intervals ne se superposent pas
                if (interval2[1] < interval1[0] || interval2[0] > interval1[1])
                {
                    continue;
                }
                // sinon le premier
            }
        }
    }

    long long min = ranges[0][0];
    for (size_t i = 0; i < ranges.size(); i++)
    {
        if (ranges[i][0] < min)
        {
            min = ranges[i][0];
        }
    }
    std::cout << min;
}