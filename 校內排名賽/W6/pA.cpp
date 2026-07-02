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
    int t; for (cin >> t; t--;) {
        string s; cin >> s;
        bitset<32> a(stoi(s)), b(stoi(s, 0, 16));
        cout << a.count() << ' ' << b.count() << '\n';
    }
}