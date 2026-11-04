#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LLONG_MAX
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIII tuple<int, int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<priority_queue<PII, vector<PII>, greater<PII>>> vpq(1000000);
vector<int> v(1000000), dp(1000000);
int k, l, n;

int f(int x) {
    auto &q = vpq[x];
    if (q.empty()) {
        for (int i = 1; i <= k; i++) q.push({0, x*k+i});
    }
    while (q.top().fi != v[q.top().se] + dp[q.top().se]) q.pop();
    return q.top().se;
}

signed main() { WA();
    cin >> k >> l >> n;

    if (k == 1) {
        int sum = 0, x;
        while (n--) cin >> x, sum += x;
        cout << (l-1)*sum << '\n';
    }
    else {
        while (n--) {
            vector<int> path = {0};
            int x, now = 0; cin >> x;
            for (int d = 0; d < l-1; d++) {
                int to = f(now);
                v[to] += x;
                now = to;
                path.pb(now);
            }

            for (int i = path.size()-2; i >= 0; i--) {
                int u = path[i], t = path[i+1];
                vpq[u].push({v[t] + dp[t], t});
                int mn = f(u);
                dp[u] = v[mn] + dp[mn];
            }
        }
        cout << dp[0] << '\n';
    }
}