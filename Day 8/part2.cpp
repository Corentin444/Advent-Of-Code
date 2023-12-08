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

int getSteps(std::map<std::string, std::pair<std::string, std::string>> nodes, std::string directions, std::string cur)
{
    int steps = 0;
    while (cur.at(2) != 'Z')
    {
        if (directions.at(steps % directions.size()) == 'L')
        {
            cur = nodes[cur].first;
        }
        else
        {
            cur = nodes[cur].second;
        }
        steps++;
    }
    return steps;
}

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

    std::vector<int> steps;
    for (std::string cur : cur_nodes)
    {
        steps.push_back(getSteps(nodes, directions, cur));
    }

    ans = steps[0];
    for (auto step : steps)
    {
        ans = std::lcm(ans, step);
    }

    std::cout << ans;
}