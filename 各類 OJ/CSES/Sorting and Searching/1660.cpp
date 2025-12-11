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
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    int ans = 0;
    for (int l = 0, r = 0, sum = 0; r < n;) {
        sum += v[r++];
        while (sum > x) sum -= v[l++]; 
        if (sum == x) ans++;
    }
    cout << ans;
}