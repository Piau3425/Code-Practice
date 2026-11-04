#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIII tuple<int, int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    for (int n, m; cin >> n >> m;) {
        vector<vector<int>> v(n, vector<int>(m)), dp = v;
        vector<vector<int>> path(n, vector<int>(m));
        for (auto &i : v) for (auto &j : i) cin >> j;
        for (int i = 0; i < n; i++) dp[i][m-1] = v[i][m-1];
        for (int i = m-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                vector<int> gay = {(j-1+n)%n, (j+1)%n, j}; sort(all(gay));
                int mn = INF;
                for (auto &nigg : gay) {
                    if (dp[nigg][i+1] < mn) {
                        mn = dp[nigg][i+1];
                        path[j][i] = nigg;
                    }
                }
                dp[j][i] = v[j][i] + mn;
            }
        }

        int ans = INF, start = 0;
        for (int i = 0; i < n; i++) if (dp[i][0] < ans) start = i, ans = dp[i][0];
        for (int i = 0; i < m-1; start = path[start][i++]) cout << start+1 << ' ';
        cout << start+1 << '\n' << ans << '\n';
    }
}