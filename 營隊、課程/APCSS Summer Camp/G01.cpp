#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &i : v) cin >> i.first >> i.second;
    sort(v.begin(), v.end(), cmp);
    for (auto i : v) cout << i.first << ' ' << i.second << '\n';
}