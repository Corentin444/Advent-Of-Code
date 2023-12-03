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

    for (std::string line : readLines("input.txt"))
    {
        std::vector<std::string> splited = split(line, " ");
    }

    std::vector<std::vector<char>> grid = readChars("input.txt");
    for (size_t x = 0; x < grid.size(); x++)
    {
        for (size_t y = 0; y < grid[0].size(); y++)
        {
            
        }
    }

    std::cout << ans;
}