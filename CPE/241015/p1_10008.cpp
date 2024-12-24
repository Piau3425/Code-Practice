#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, char> a, pair<int, char> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    int n;
    char c;
    vector<pair<int, char>> v(26);
    for (int i = 0; i < 26; i++) v[i] = {0, i + 'A'};
    cin >> n;
    while (cin >> c) if (isalpha(c)) v[toupper(c)-'A'].first++;
    sort(v.begin(), v.end(), cmp);
    for (auto i : v) if (i.first > 0) cout << i.second << ' ' << i.first << '\n';
}