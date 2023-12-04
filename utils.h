#pragma once

#include <vector>
#include <string>
#include <regex>
#include <iterator>
#include <fstream>

// Split a string by a delimiter
std::vector<std::string> splitByString(std::string s, std::string delimiter)
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
std::vector<std::string> splitByRegex(std::string s, std::string regex)
{
    std::regex split_regex(regex);
    std::vector<std::string> splitted;
    std::sregex_token_iterator words_begin = std::sregex_token_iterator(s.begin(), s.end(), split_regex, -1);
    std::sregex_token_iterator words_end = std::sregex_token_iterator();
    for (std::sregex_token_iterator i = words_begin; i != words_end; ++i)
    {
        std::string match_string = *i;
        splitted.push_back(match_string);
    }
    return splitted;
}

// Get all regex matches in a string
std::vector<std::string> getRegexMatches(std::string s, std::string regex)
{
    std::regex match_regex(regex);
    std::vector<std::string> matches;
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), match_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_string = match.str();
        matches.push_back(match_string);
    }
    return matches;
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

// Read chars from a file
std::vector<std::vector<char>> readChars(std::string fileName)
{
    std::vector<std::vector<char>> chars = {};
    std::ifstream infile(fileName);
    std::string line;
    int i = 0;
    while (std::getline(infile, line))
    {
        chars.push_back({});
        for (char c : line)
        {
            chars[i].push_back(c);
        }
        i++;
    }
    return chars;
}

template <typename T>
bool contains(std::vector<T> haystack, T needle)
{
    return std::find(haystack.begin(), haystack.end(), needle) != haystack.end();
}