#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>

int main()
{
    std::ifstream infile("input.txt");
    std::string line;
    int sum = 0;
    int lineId = 1;
    bool possible;
    std::map<std::string, int> colors = {{"r", 12}, {"g", 13}, {"b", 14}};
    while (std::getline(infile, line))
    {
        std::cout << " ***" << lineId << " ***\n";
        possible = true;
        std::regex word_regex("([0-9]+\\sr)|([0-9]+\\sg)|([0-9]+\\sb)");
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), word_regex);
        auto words_end = std::sregex_iterator();
        std::cout << "Found " << std::distance(words_begin, words_end) << " words:\n";

        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch m1 = *i;
            std::string s1 = m1.str();
            int n1 = std::stoi(s1.substr(0, s1.size() - 2));
            std::string c1 = s1.substr(s1.size() - 1);
            // std::cout << n1 << " " << c1 << " " << colors[c1] << "\n";
            if(n1 > colors[c1])
            {
                possible = false;
                std::cout << lineId << " is false\n";
                break;
            }
        }

        if(possible)
        {
            std::cout << lineId << "\n";
            sum += lineId;
        }
        lineId++;
    }

    std::cout << sum;
}