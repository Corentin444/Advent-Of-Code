#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

int main()
{
    std::ifstream infile("input.txt");
    std::string line;
    int sum = 0;
    std::vector<int> numbers;
    while (std::getline(infile, line))
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