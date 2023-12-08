#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <numeric>
#include <algorithm>
#include <utility>

#include "../utils.h"

using namespace std;
int main()
{
    int ans = 0;

    for (string line : readLines("input.txt"))
    {
        vector<string> splited = splitByString(line, " ");
    }

    vector<vector<char>> grid = readChars("input.txt");
    for (size_t x = 0; x < grid.size(); x++)
    {
        for (size_t y = 0; y < grid[0].size(); y++)
        {
        }
    }

    cout << ans;
}
