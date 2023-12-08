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
    int ans = 0;

    vector<vector<char>> grid = readChars("input.txt");
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    map<pair<int, int>, vector<int>> gears;

    for (size_t x = 0; x < grid.size(); x++)
    {
        string n = "";
        bool gear = false;
        int gearX = -1;
        int gearY = -1;

        for (size_t y = 0; y < grid[0].size(); y++)
        {
            char c = grid[x][y];
            if (isdigit(c))
            {
                n += c;
                for (auto dir : dirs)
                {
                    int xx = x + dir[0];
                    int yy = y + dir[1];
                    if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size() && grid[xx][yy] == '*')
                    {
                        gear = true;
                        gearX = xx;
                        gearY = yy;
                        break;
                    }
                }
            }
            else
            {
                if (n != "" && gear)
                {
                    pair<int, int> gearPos(gearX, gearY);
                    gears[gearPos].push_back(stoi(n));
                }
                n = "";
                gear = false;
                gearX = -1;
                gearY = -1;
            }
        }

        if (n != "" && gear)
        {
            pair<int, int> gearPos(gearX, gearY);
            gears[gearPos].push_back(stoi(n));
        }
    }

    for (auto const &[gearPos, val] : gears)
    {
        if (val.size() == 2)
        {
            ans += val[0] * val[1];
        }
    }
    cout << ans;
}