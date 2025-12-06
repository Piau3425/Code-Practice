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
    for (int n; cin >> n;) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        queue<PII> q; q.push({0, n});
        int t = 0;
        while (q.size()) {
            auto [l, r] = q.front(); q.pop();
            cout << ++t << " person is given with these numbers :";
            for (int i = l; i < r; i++) cout << v[i] << ' '; cout << '\n';
            if (r-l > 1) {
                int m = l + ((r-l)>>1);
                if (r-l & 1) m++;
                q.push({l, m}); q.push({m, r});
            }
        }
        sort(all(v));
        cout << "After Sorting the elements are :";
        for (auto &i : v) cout << ' ' << i;
    }
}