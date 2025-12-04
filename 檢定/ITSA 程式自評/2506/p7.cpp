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
    int m; cin >> m;
    while (m--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto &i : v) {
            int tmp;
            cin >> tmp >> i;
        }
        sort(all(v));
        int sum = 0;
        while (n > 3) {
            sum += min(v[0]*2+v[n-2]+v[n-1], v[0]+v[1]*2+v[n-1]);
            n -= 2;
        }
        if (n == 1) sum += v[0];
        else if (n == 2) sum += v[1];
        else if (n == 3) sum += v[0]+v[1]+v[2];
        cout << sum << '\n';
    }
}