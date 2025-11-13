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
    int n; cin >> n; vector<PII> v(n);
    for (auto &i : v) cin >> i.fi >> i.se;
    sort(all(v));
    priority_queue<int, vector<int>, greater<int>> pq; int mx = -1e9;
    for (auto &[sta, ed] : v) {
        while (pq.size() && pq.top() < sta) pq.pop();
        pq.push(ed);
        mx = max(mx, (int)pq.size());
    }
    cout << mx << '\n';
}