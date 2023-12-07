#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <algorithm>
#include <utility>
#include <ranges>

#include "../utils.h"

float getValue(const std::map<char, int> &cards, std::string hand)
{
    float value = 0;
    for (auto const &[key, val] : cards)
    {
        if (key != 'J')
        {
            if (std::ranges::count(hand, key) > 2)
            {
                value += std::ranges::count(hand, key);
            }
            else if (std::ranges::count(hand, key) == 2)
            {
                value += 0.5;
            }
        }
    }
    int nbJ = std::ranges::count(hand, 'J');
    if (nbJ > 0)
    {
        if (value == 4 || value == 3)
        {
            value += nbJ;
        }
        else if (value == 1)
        {
            value = 3.5;
        }
        else if (value == 0.5)
        {
            value += 1.5 + nbJ;
        }
        else if (value == 0)
        {
            if (nbJ == 1)
            {
                value = 0.5;
            }
            else
            {
                value = std::min(1 + nbJ, 5);
            }
        }
    }
    if (nbJ > 2)
    {

        std::cout << hand << " " << value << " points\n";
    }

    return value;
}
bool comparaison(const std::map<char, int> &cards, std::string handA, std::string handB)
{
    float scoreA = getValue(cards, handA);
    float scoreB = getValue(cards, handB);
    if (scoreA != scoreB)
    {
        return scoreA > scoreB;
    }
    else
    {
        for (size_t i = 0; i < 5; i++)
        {
            char aa = handA[i];
            char bb = handB[i];
            if (aa != bb)
            {
                return cards.at(aa) > cards.at(bb);
            }
        }
    }
    return true;
}
int main()
{
    int ans = 0;
    std::map<char, int> cards = {{'A', 13}, {'K', 12}, {'Q', 11}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}, {'J', 1}};

    std::vector<std::pair<std::string, int>> hands;
    for (std::string line : readLines("input.txt"))
    {
        std::vector<std::string> splited = splitByString(line, " ");
        std::string hand = splited[0];
        int bid = std::stoi(splited[1]);

        std::pair<std::string, int> pair(hand, bid);
        hands.push_back(pair);
    }

    std::sort(hands.begin(), hands.end(), [cards](std::pair<std::string, int> &a, std::pair<std::string, int> &b)
              { return comparaison(cards, a.first, b.first); });

    int rank = hands.size();
    for (auto hand : hands)
    {
        ans += rank * hand.second;
        rank--;
    }

    std::cout << ans;
}