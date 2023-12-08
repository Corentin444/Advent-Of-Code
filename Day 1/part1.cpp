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
    for(string line : readLines("input.txt"))
    {
        for (char c : line)
        {
            if (isdigit(c))
            {
                numbers.push_back(c - '0');
            }
        }
        sum = sum + numbers[0] * 10 + numbers[numbers.size() - 1];
        numbers = {};
    }

    cout << sum;
}