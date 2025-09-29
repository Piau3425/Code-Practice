#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, x;
    cin >> m >> x;
    vector<unordered_set<int>> s(m+1);
    for (int i = 1; i <= m; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            s[i].insert(tmp);
        }
    }

    while (x--) {
        int n, sum = 0;
        unordered_set<int> d;
        cin >> n;
        while (n--) {
            int t;
            cin >> t;
            for (auto i : s[t]) d.insert(i);
        }
        cout << d.size() << '\n';
    }
}