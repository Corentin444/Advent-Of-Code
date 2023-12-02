#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <algorithm>

#include "../utils.h"

int main()
{
    int ans = 0;
    
    for(std::string line : readLines("input.txt"))
    {
        std::vector<std::string> splited = split(line, " ");
    }

    std::cout << ans;
}