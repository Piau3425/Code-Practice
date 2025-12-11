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
    int n; for (cin >> n; n--;) {
        string s; cin >> s;
        int a, b; a = b = 0;
        for (auto &c : s) {
            bitset<10000> bs(c-'0');
            a += bs.count();
        }
        bitset<100000> bs(stoll(s));
        cout << bs.count() << ' ' << a << '\n';
    }
}