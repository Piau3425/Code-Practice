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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    int sum = 0, ans = -1e9, cnt = 0;
    for (int l = 0, r = 0; r < n; r++) {
        sum += v[r];
        while (sum > k) sum -= v[l], l++;
        if (sum > ans) ans = sum, cnt = 1;
        else if (sum == ans) cnt++;
    }
    cout << ans << '\n' << cnt;
}