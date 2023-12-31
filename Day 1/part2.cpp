#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "../utils.h"

using namespace std;

int main()
{
    int sum = 0;
    vector<int> numbers;
    size_t pos;
    map<string, int> symbolTable = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    for(string line : readLines("input.txt"))
    {
        for (int i = 0; i < line.size(); i++)
        {
            char c = line[i];
            if (isdigit(c))
            {
                numbers.push_back(c - '0');
            }

            for(auto const &[key, val] : symbolTable)
            {
                if(i <= line.size() - key.size())
                {
                    if(line.substr(i, key.size()) == key)
                    {
                        numbers.push_back(val);
                    }
                }
            }
        }
        sum = sum + numbers[0] * 10 + numbers[numbers.size() - 1];
        numbers = {};
    }

    cout << sum;
}