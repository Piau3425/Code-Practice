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
    int m, n;
    while (cin >> m >> n) {
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<int> cnt(m+1);
        vector<tuple<int, int, int>> v(n);
        for (auto &i : v) {
            auto &[a, b, c] = i;
            cin >> a >> c; b = &i-v.data();
        }
        sort(all(v));
        for (int i = 1; i <= m; i++) pq.push({0, i});
        for (auto &i : v) {
            auto [a, ignore, t] = i;
            if (pq.top().fi <= a) {
                cnt[pq.top().se]++;
                pq.push({a+t, pq.top().se});
                pq.pop();
            }
        }
        for (int i = 1; i <= m; i++) cout << cnt[i] << " \n"[i==m];
    }
}