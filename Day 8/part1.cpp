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

    std::map<std::string, std::pair<std::string, std::string>> nodes;
    std::vector<std::string> lines = readLines("input.txt");
    std::string directions = lines[0];

    for (size_t i = 2; i < lines.size(); i++)
    {
        std::string line =  lines[i];
        std::string node = line.substr(0, 3);
        std::string left = line.substr(7, 3);
        std::string right = line.substr(12, 3);
        std::pair<std::string, std::string> pair (left, right);
        nodes[node] = pair;
    }
    
    std::string cur = "AAA";
    int i = 0;
    while(cur != "ZZZ")
    {
        // std::cout << cur << " + " << directions.at(i) << " = ";
        if(directions.at(i) == 'L')
        {
            cur = nodes[cur].first;
        } else {
            cur = nodes[cur].second;
        }
        ans++;
        // std::cout << cur << "\n";
        i++;
        i = i % directions.size();
    }

    std::cout << ans;
}