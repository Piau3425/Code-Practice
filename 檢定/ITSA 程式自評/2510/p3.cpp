#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    map<char, int> mp = {
        {'L', 1},
        {'Z', 2},
        {'E', 3},
        {'A', 4},
        {'S', 5},
        {'H', 6},
        {'J', 7},
        {'B', 8},
        {'G', 9},
        {'O', 10}
    };

    int t; for (cin >> t, cin.ignore(); t--;) {
        string s; getline(cin, s);
        int sum = 0;
        for (auto &c : s) if (isalpha(c)) {
            sum += mp[toupper(c)];
        }
        cout << sum << '\n';
    }
}