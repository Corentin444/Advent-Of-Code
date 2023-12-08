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

vector<long long> remap(long long first, long long last, vector<vector<long long>> map)
{
    vector<long long> res;
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
    vector<string> lines = readLines("input.txt");
    vector<pair<long long, long long>> intervals;
    vector<string> firstLine = splitByString(splitByString(lines[0], ": ")[1], " ");
    for (int i = 1; i < firstLine.size(); i += 2)
    {
        long long start = stoll(firstLine[i]);
        long long end = start + stoll(firstLine[i + 1]) - 1;
        pair<long long, long long> interval(start, end);
        intervals.push_back(interval);
    }

    for (size_t i = 2; i < lines.size(); i++)
    {
        string line = lines[i];
        if (line == "")
        {
            continue;
        }

        if (line.find(":") != string::npos)
        {
            for (size_t i = 0; i < done.size(); i++)
            {
                done[i] = false;
            }
        }
        else
        {
            // ligne avec nombres
            long long destStart = stoll(splitByString(line, " ")[0]);   // 10
            long long srcStart = stoll(splitByString(line, " ")[1]);    // 25
            long long rangeLength = stoll(splitByString(line, " ")[2]); // 3
            pair<long long, long long> interval2(srcStart, srcStart + rangeLength - 1);

            for (pair<long long, long long> interval1 : intervals)
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
    cout << min;
}