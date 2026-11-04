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

int dp[105][105];

signed main() { WA();
    int n, m; cin >> m >> n; cin.ignore();
    vector<int> cnt(m+1); for (int i = 1; i <= m; i++) cin >> cnt[i];
    vector<vector<int>> v(m+1);
    for (int i = 1; i <= m; i++) {
        v[i].pb(0);
        for (int j = 1; j <= cnt[i]; j++) {
            int x; cin >> x;
            v[i].pb(v[i][j-1]+x);
        }
    }

    for (auto &i : dp) fill(i, i+105, -INF); dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 0; j--) {
            for (int k = 0; k <= min(j, (int)v[i].size()-1); k++) {
                if (dp[i-1][j-k] != -INF) dp[i][j] = max(dp[i][j], dp[i-1][j-k] + v[i][k]);
            }
        }
    }
    vector<int> chosen(m+1); int j = n;
    for (int i = m; i >= 1; i--) {
        for (int k = 0; k <= min(j, (int)v[i].size()-1); k++) {
            if (dp[i-1][j-k] != -INF && dp[i][j] == dp[i-1][j-k] + v[i][k]) {
                j -= k;
                chosen[i] = k;
                break;
            }
        }
    }
    cout << dp[m][n] << '\n';
    int flag = 0;
    for (int i = 1; i <= m; i++) if (chosen[i]) cout << (flag++ ? " (" : "(") << i << ',' << chosen[i] << ')';
    cout << '\n';
}