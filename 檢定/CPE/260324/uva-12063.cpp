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

int dp[65][65][101], n, k;

int f(int idx, int cnt, int mod) {
    int &ret = dp[idx][cnt][mod];
    if (idx == n) return cnt == n/2 && !mod;
    if (~ret) return ret;
    
    ret = 0;
    if (idx-cnt < n/2) ret += f(idx+1, cnt, mod*2%k);
    if (cnt < n/2) ret += f(idx+1, cnt+1, (mod*2+1)%k);
    return ret;
}

signed main() { WA();
    int t = 1, T; for (cin >> T; t <= T; t++) { cout << "Case " << t << ": ";
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        if (!k) cout << "0\n";
        else cout << f(1, 1, 1) << '\n';
    }
}