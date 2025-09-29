#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    double max, one, lost, cut = 0;
    int cnt = 0;
    string s;
    cin >> max >> s;
    if (s == "m") max *= 100;
    cin >> one >> s;
    if (s == "m") one *= 100;
    cin >> lost >> s;
    if (s == "m") lost *= 100;

    while (cut+one < max) {
        cnt++;
        cut = cut + one - lost;
    }
    cout << cnt + 1;
}