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
    int n, m;
    for (cin >> n; n--;) {
        cin >> m; vector<int> v(m);
        for (auto &i : v) cin >> i;
        sort(all(v));

        int sum = 0;
        for(int i = 0; i < m; i++) sum += abs(v[(m/2)-1 + (m%2)] - v[i]);
        cout << sum << '\n';
    }
}