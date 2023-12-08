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

using namespace std;

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
    cout << "a=" << a << "\n";
    cout << "b=" << b << "\n";
    cout << "b=" << c << "\n";

    long long x1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
    cout << sqrt((b * b) - (4 * a * c)) << "\n";
    cout << "x1 = " << x1 << "\n";
    long long x2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
    cout << "x2 = " << x2 << "\n";

    ans = x1 - x2;
    cout << ans;
}