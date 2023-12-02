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
    std::size_t pos;
    std::map<std::string, std::string> symbolTable = {{"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};
    while (std::getline(infile, line))
    {
        for (auto const &[key, val] : symbolTable)
        {
            pos = line.find(key);
            while (pos != std::string::npos)
            {
                line.replace(pos, 1, val);
                pos = line.find(key);
            }
        }
        for (char c : line)
        {
            if (isdigit(c))
            {
                std::cout << c << " ";
                numbers.push_back(c - '0');
            }
        }
        std::cout << std::endl;
        sum = sum + numbers[0] * 10 + numbers[numbers.size() - 1];
        numbers = {};
    }

    std::cout << sum;
}