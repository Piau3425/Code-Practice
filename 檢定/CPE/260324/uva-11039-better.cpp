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
        int n; cin >> n;
        if (!n) {
            cout << "0\n";
            continue;
        }
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        sort(all(v), [](int a, int b) {
            return abs(a) > abs(b);
        });
        int k = v.front() >> 31 | 1 , cnt = 1;
        for (auto &i : v) if (k*i < 0) k *= -1, cnt++;
        cout << cnt << '\n';
    }
}