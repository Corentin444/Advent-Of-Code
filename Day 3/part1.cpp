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
    std::vector<std::vector<char>> grid = readChars("input.txt");
    std::vector<std::vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    for (size_t x = 0; x < grid.size(); x++)
    {
        std::string n = "";
        bool symbol = false;
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
                    if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size())
                    {
                        if (!isdigit(grid[xx][yy]) && grid[xx][yy] != '.')
                        {
                            symbol = true;
                            break;
                        }
                    }
                }
            }
            else
            {
                if (n != "" && symbol)
                {
                    ans += std::stoi(n);
                }
                n = "";
                symbol = false;
            }
        }

        if (n != "" && symbol)
        {
            ans += std::stoi(n);
        }
    }

    std::cout << ans;
}