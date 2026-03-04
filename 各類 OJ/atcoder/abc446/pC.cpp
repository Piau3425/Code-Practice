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

int now = 0;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    now = 0;
    queue<PII> q;
    for (int i = 0; i < n; i++) {
        q.push({i, a[i]});
        while (b[i] && q.size()) {
            if (b[i] >= q.front().se) b[i] -= q.front().se, q.pop();
            else {
                q.front().se -= b[i];
                break;
            }
        }
        while (q.size() && i - q.front().fi >= d) q.pop();
    }
    int sum = 0;
    while (q.size()) sum += q.front().se, q.pop();
    cout << sum << '\n';
}

signed main() { WA();
    int t; for (cin >> t; t--;) solve();
}