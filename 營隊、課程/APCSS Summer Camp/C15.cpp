#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c(n, {0, 0}); // 錢, 小孩幾人
    vector<int> p(n, 0);
    set<int> k;
    for (auto &i : c) cin >> i.first;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        c[p[i]].second++;
    }
    while (m--) {
        int tmp;
        cin >> tmp;
        k.insert(tmp);
    }

    for (int i = 1; i < n; i++) {
        if (k.count(i)) continue;
        c[i].first += c[p[i]].first/(c[p[i]].second-1);
    }
    for (auto i : c) cout << i.first << ' ';
}