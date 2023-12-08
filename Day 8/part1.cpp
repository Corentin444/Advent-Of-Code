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

    map<string, pair<string, string>> nodes;
    vector<string> lines = readLines("input.txt");
    string directions = lines[0];

    for (size_t i = 2; i < lines.size(); i++)
    {
        string line =  lines[i];
        string node = line.substr(0, 3);
        string left = line.substr(7, 3);
        string right = line.substr(12, 3);
        pair<string, string> pair (left, right);
        nodes[node] = pair;
    }
    
    string cur = "AAA";
    while(cur != "ZZZ")
    {
        if(directions.at(ans % directions.size()) == 'L')
        {
            cur = nodes[cur].first;
        } else {
            cur = nodes[cur].second;
        }
        ans++;
    }

    cout << ans;
}