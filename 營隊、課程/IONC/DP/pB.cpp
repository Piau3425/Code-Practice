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

int dp[20][10][2][2];

int dfs(string &num, int now, int last, int zero, int limit) {
    int &ret = dp[now][last][zero][limit];
    if (!now) return ret = 1;
    if (~ret) return ret;
    int ans = 0, chr = num[num.size()-now]-'0';
    for (int i = 0; i <= (limit ? chr : 9); i++) {
        if (!zero && i == last) continue;
        ans += dfs(num, now-1, i, (zero && !i), (limit && i == chr));
    }
    return ret = ans;
}

signed main() { WA();
    int a, b;
    while (cin >> a >> b) {
        string sa = to_string(a-1), sb = to_string(b);
        memset(dp, -1, sizeof(dp));
        int bb = dfs(sb, sb.size(), -1, 1, 1);
        memset(dp, -1, sizeof(dp));
        cout << bb - dfs(sa, sa.size(), -1, 1, 1) << '\n';
    }
}