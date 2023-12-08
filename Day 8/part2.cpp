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

int getSteps(map<string, pair<string, string>> nodes, string directions, string cur)
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

    map<string, pair<string, string>> nodes;
    vector<string> lines = readLines("input.txt");
    string directions = lines[0];
    vector<string> cur_nodes;

    for (size_t i = 2; i < lines.size(); i++)
    {
        string line = lines[i];
        string node = line.substr(0, 3);
        string left = line.substr(7, 3);
        string right = line.substr(12, 3);
        pair<string, string> pair(left, right);
        nodes[node] = pair;
        if (node.at(2) == 'A')
        {
            cur_nodes.push_back(node);
        }
    }

    vector<int> steps;
    for (string cur : cur_nodes)
    {
        steps.push_back(getSteps(nodes, directions, cur));
    }

    ans = steps[0];
    for (auto step : steps)
    {
        ans = lcm(ans, step);
    }

    cout << ans;
}