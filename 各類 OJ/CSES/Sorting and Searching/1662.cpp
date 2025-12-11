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
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    int ans = 0;
    vector<int> pre(n+1), cnt(n); cnt[0] = 1;
    for (int i = 1; i <= n; i++) pre[i] = v[i-1]+pre[i-1];
    for (int i = 1; i <= n; i++) {
        int now = (pre[i]%n+n)%n;
        ans += cnt[now];
        cnt[now]++;
    }
    cout << ans;
}

// pre[i]%n == pre[j-1]%n