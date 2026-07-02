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
    int k = 0;
    for (string s; getline(cin, s);) {
        for (auto &c : s) if (c == '"') {if (k^=1) cout << "``"; else cout << "''";} else cout << c;
        cout << '\n';
    }
}