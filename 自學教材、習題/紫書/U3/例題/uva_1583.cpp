#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>


signed main() { WA();
    map<int, int> mp;

    for (int i = 1; i <= 100000; i++) {
        string s = to_string(i);
        int sum = i;
        for (auto &c : s) sum += c - '0';
        if (!mp[sum] || i < mp[sum]) mp[sum] = i;
    }

    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        cout << mp[t] << '\n';
    }
}