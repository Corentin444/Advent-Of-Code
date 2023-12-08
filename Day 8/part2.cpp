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

int main()
{
    long long ans = 0;

    std::map<std::string, std::pair<std::string, std::string>> nodes;
    std::vector<std::string> lines = readLines("input.txt");
    std::string directions = lines[0];
    std::vector<std::string> cur_nodes;

    for (size_t i = 2; i < lines.size(); i++)
    {
        std::string line = lines[i];
        std::string node = line.substr(0, 3);
        std::string left = line.substr(7, 3);
        std::string right = line.substr(12, 3);
        std::pair<std::string, std::string> pair(left, right);
        nodes[node] = pair;
        if (node.at(2) == 'A')
        {
            cur_nodes.push_back(node);
        }
    }

    int n = 0;
    int pos = 0;
    std::vector<int> steps;
    bool finish = false;
    for(auto cur : cur_nodes)
    {
        while(cur.at(2) != 'Z')
        {
            if(directions.at(pos) == 'L')
            {
                cur = nodes[cur].first;
            } else {
                cur = nodes[cur].second;
            }
            pos++;
            pos = pos % directions.size();
            n++;
        }
        steps.push_back(n);
        n = 0;
        pos = 0;
    }

    ans = steps[0];
    for (auto step: steps)
    {
        ans = std::lcm(ans, step);
    }
   

    std::cout << ans;
}