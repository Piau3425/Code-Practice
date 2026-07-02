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
        vector<vector<int>> v(n, vector<int>(n));
        for (auto &i : v) {
            for (auto &j : i) cin >> j;
            sort(all(i));
        }
        for (int i = 0; i+1 < n; i++) {
            priority_queue<PII, vector<PII>, greater<PII>> pq;
            vector<int> &a = v[i], &b = v[i+1];
            for (auto &i : a) pq.push({i+b[0], 0});
            for (int i = 0; i < n; i++) {
                auto [p, q] = pq.top(); pq.pop();
                a[i] = p;
                if (q+1 < n) pq.push({p-b[q]+b[q+1], q+1});
            }
            b = a;
        }
        for (auto &i : v.back()) cout << i << " \n"[&i == &v.back().back()];
    }
}