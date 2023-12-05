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
    int ans = 0;
    std::vector<std::string> lines = readLines("input.txt");
    std::vector<std::pair<int, int>> srcDes;
    for (std::string s : splitByString(splitByString(lines[0], ": ")[1], " "))
    {
        if (s != "")
        {
            std::pair<int, int> a(0, std::stoi(s));
            srcDes.push_back(a);
        }
    }

    for (size_t i = 2; i < lines.size(); i++)
    {
        std::string line = lines[i];
        if (line == "")
        {
            // ligne vide
            continue;
        }

        if (line.find(":") != std::string::npos)
        {
            // nouvelle ligne
            for (std::pair<int, int> pair : srcDes)
            {
                int tmp = pair.first;
                pair.first = pair.second;
                pair.second = tmp;
            }

            std::cout << " Destinations : ";
            for (std::pair<int, int> pair : srcDes)
            {
                std::cout << pair.second << " ";
            }
            std::cout << "\n Sources : ";
            for (std::pair<int, int> pair : srcDes)
            {
                std::cout << pair.first << " ";
            }
            std::cout << "\n" << line << "\n";
        }
        else
        {
            // ligne avec nombres
            int destStart = std::stoi(splitByString(line, " ")[0]);
            int srcStart = std::stoi(splitByString(line, " ")[1]);
            int rangeLength = std::stoi(splitByString(line, " ")[2]);
            for (std::pair<int, int> pair : srcDes)
            {
                if (pair.first >= srcStart && pair.first < srcStart + rangeLength)
                {
                    pair.second = destStart + pair.first - srcStart;
                }
            }
        }
    }

    for (std::pair<int, int> pair : srcDes)
    {
        std::cout << pair.second << "\n";
    }
}