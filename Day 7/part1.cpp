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
        if (std::ranges::count(hand, key) > 2)
        {
            value += std::ranges::count(hand, key);
        }
        else if (std::ranges::count(hand, key) == 2)
        {
            value += 0.5;
        }
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
    std::map<char, int> cards = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};

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