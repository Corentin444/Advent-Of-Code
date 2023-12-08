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

using namespace std;

float getValue(const map<char, int> &cards, string hand)
{
    float value = 0;
    for (auto const &[key, val] : cards)
    {
        if (ranges::count(hand, key) > 2)
        {
            value += ranges::count(hand, key);
        }
        else if (ranges::count(hand, key) == 2)
        {
            value += 0.5;
        }
    }
    return value;
}
bool comparaison(const map<char, int> &cards, string handA, string handB)
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
    map<char, int> cards = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};

    vector<pair<string, int>> hands;
    for (string line : readLines("input.txt"))
    {
        vector<string> splited = splitByString(line, " ");
        string hand = splited[0];
        int bid = stoi(splited[1]);

        pair<string, int> pair(hand, bid);
        hands.push_back(pair);
    }

    sort(hands.begin(), hands.end(), [cards](pair<string, int> &a, pair<string, int> &b)
              { return comparaison(cards, a.first, b.first); });

    int rank = hands.size();
    for (auto hand : hands)
    {
        ans += rank * hand.second;
        rank--;
    }

    cout << ans;
}