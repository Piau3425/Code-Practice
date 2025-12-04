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
    int n, len; cin >> n >> len;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    deque<int> qmx, qmn;
    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        if (qmx.size() && qmx.front() <= i-len) qmx.pop_front();
        if (qmn.size() && qmn.front() <= i-len) qmn.pop_front();
        while (qmx.size() && v[qmx.back()] <= v[i]) qmx.pop_back(); qmx.push_back(i);
        while (qmn.size() && v[qmn.back()] >= v[i]) qmn.pop_back(); qmn.push_back(i);
        ans = max(ans, v[qmx.front()]-v[qmn.front()]);
    }
    cout << ans;
}