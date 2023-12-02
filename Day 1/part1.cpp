#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "../utils.h"

int main()
{
    int sum = 0;
    std::vector<int> numbers;
    for(std::string line : readLines("input.txt"))
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

    std::cout << sum;
}