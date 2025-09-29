#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, len, now = 0; cin >> n >> len;
    vector<int> v(n), cnt(n);
    for (auto &i : v) cin >> i;
    for (int i = 0; i < len; i++) if (++cnt[v[i]] == 1) now++;
    int ans = now;
    for (int i = len; i < n; i++) {
        if (++cnt[v[i]] == 1) now++;
        if (--cnt[v[i-len]] == 0) now--;
        ans = max(ans, now);
    }
    cout << ans;
}