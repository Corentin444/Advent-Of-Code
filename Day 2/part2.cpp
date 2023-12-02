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
    std::map<std::string, int> colors;
    while (std::getline(infile, line))
    {
        colors = {{"r", -1}, {"g", -1}, {"b", -1}};
        std::regex word_regex("([0-9]+\\sr)|([0-9]+\\sg)|([0-9]+\\sb)");
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), word_regex);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch m1 = *i;
            std::string s1 = m1.str();
            int n1 = std::stoi(s1.substr(0, s1.size() - 2));
            std::string c1 = s1.substr(s1.size() - 1);
            // std::cout << n1 << " " << c1 << " " << colors[c1] << "\n";
            if(n1 > colors[c1])
            {
                colors[c1] = n1;
            }
        } 
        std::cout << colors["r"] << " " << colors["g"] << " " << colors["b"] << "\n";
        sum += colors["r"] * colors["g"] * colors["b"];
    }

    std::cout << sum;
}