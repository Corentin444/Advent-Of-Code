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
    long long ans = 0;
    vector<string> lines = readLines("input.txt");
    vector<long long> numbers;
    vector<bool> done;
    for (string s : splitByString(splitByString(lines[0], ": ")[1], " "))
    {
        if (s != "")
        {
            cout << s << "\n";
            cout << stoll(s) << "\n";
            numbers.push_back(stoll(s));
            done.push_back(false);
        }
    }

    for (size_t i = 2; i < lines.size(); i++)
    {
        string line = lines[i];
        if (line == "")
        {
            // ligne vide
            continue;
        }

        if (line.find(":") != string::npos)
        {
            // nouvelle ligne
            for (size_t i = 0; i < done.size(); i++)
            {
                done[i] = false;
            }
        }
        else
        {
            // ligne avec nombres
            long long destStart = stoll(splitByString(line, " ")[0]);
            long long srcStart = stoll(splitByString(line, " ")[1]);
            long long rangeLength = stoll(splitByString(line, " ")[2]);
            for (size_t i = 0; i < numbers.size(); i++)
            {
                long long number = numbers[i];
                bool aa = done[i];
                if (!aa && number >= srcStart && number < srcStart + rangeLength)
                {
                    numbers[i] = destStart + number - srcStart;
                    done[i] = true;
                }
            }
            for (size_t i = 0; i < numbers.size(); i++)
            {
                long long number = numbers[i];
            }
        }
    }

    long long min = numbers[0];
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    cout << min;
}