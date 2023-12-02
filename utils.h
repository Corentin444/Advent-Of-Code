#pragma once

#include <vector>
#include <string>
#include <regex>
#include <iterator>
#include <fstream>

// Split a string by a delimiter
std::vector<std::string> split(std::string s, std::string delimiter)
{
    size_t pos;
    std::vector<std::string> splitted;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        splitted.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    splitted.push_back(s);
    return splitted;
}

// Split a string by a regex
std::vector<std::string> split(std::string s, std::regex word_regex)
{
    std::vector<std::string> splitted;
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_string = match.str();
        splitted.push_back(match_string);
    }
    return splitted;
}

// Read lines from a file
std::vector<std::string> readLines(std::string fileName)
{
    std::ifstream infile(fileName);
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(infile, line))
    {
        lines.push_back(line);
    }
    return lines;
}