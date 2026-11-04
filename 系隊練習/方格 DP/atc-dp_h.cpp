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

int p = (1e9+7);

signed main() { WA();
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n+1, vector<char>(m+1, '.'));
    vector<vector<int>> dp(n+1, vector<int>(m+1)); dp[0][1] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> v[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int sum = 0;
        if (v[i-1][j] != '#') sum = (sum+dp[i-1][j])%p;
        if (v[i][j-1] != '#') sum = (sum+dp[i][j-1])%p;
        dp[i][j] = sum;
    }
    cout << dp[n][m] << '\n';
}