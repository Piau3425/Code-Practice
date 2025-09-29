#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    for (cin >> n; n; n--) {
        string c;
        cin >> c;
        if (c == "申") cout << "u7533";
        if (c == "有") cout << "u6709";
        if (c == "無") cout << "u7121";
        if (c == "月") cout << "u6708";
        if (c == "合") cout << "u5408";
        if (c == "禁") cout << "u7981";
        if (c == "割") cout << "u5272";
        if (c == "指") cout << "u6307";
        if (c == "空") cout << "u7a7a";
        if (c == "密") cout << "secret";
        if (c == "祝") cout << "congratulations";
        if (c == "可") cout << "accept";
        if (c == "中") cout << "mahjong";
        if (c == "得") cout << "ideograph_advantage";
        cout << '\n';
    }
}