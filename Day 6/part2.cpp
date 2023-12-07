#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>

#include "../utils.h"

int main()
{
    long long ans = 0;

    long long times = 34908986;
    long long record = 204171312101780;

    long long height = ((times * times) / 4) - record;
    long long width = times;

    long long a = -1;                     // la direction d'ouverture de la parabole et son degré de "pente"
    long long b = -(2 * a * (width / 2)); // la position horizontale de la parabole
    long long c = height;                 // la position verticale de la parabole
    std::cout << "a=" << a << "\n";
    std::cout << "b=" << b << "\n";
    std::cout << "b=" << c << "\n";

    long long x1 = (-b + std::sqrt((b * b) - (4 * a * c))) / (2 * a);
    std::cout << std::sqrt((b * b) - (4 * a * c)) << "\n";
    std::cout << "x1 = " << x1 << "\n";
    long long x2 = (-b - std::sqrt((b * b) - (4 * a * c))) / (2 * a);
    std::cout << "x2 = " << x2 << "\n";

    ans = x1 - x2;
    std::cout << ans;
}