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
    int n; cin >> n;
    vector<int> v(n), cnt(n);
    for (auto &i : v) cin >> i;
    int ans = -1e9;
    for (int l = 0, r = 0; r < n; r++) {
        ++cnt[v[r]];
        while (cnt[v[r]] > 1) cnt[v[l]]--, l++;
        ans = max(ans, r-l+1);  
    }
    cout << ans;
}