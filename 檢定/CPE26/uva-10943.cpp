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

int dp[101][101];

signed main() { WA();
    for (int i = 0; i <= 100; i++) dp[i][1] = 1;
    for (int i = 0; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            for (int k = 0; k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[i-k][j-1])%1000000;
            }
        }
    }
    for (int a, b; cin >> a >> b, a+b;) cout << dp[a][b] << '\n';
}