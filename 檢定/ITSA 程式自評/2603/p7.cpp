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
    int n; cin >> n;
    deque<int> dq(n);
    for (auto &i : dq) cin >> i;

    int cost = 0, o;
    while (dq.size() > 1) {
        auto k = min_element(all(dq));
        if (k == dq.begin()) o = 1;
        else if (k == prev(dq.end())) o = -1;
        else o = (k[1] < k[-1] ? 1 : -1);
        cost += k[o];
        dq.erase(k);
    }
    cout << cost <<'\n';
}