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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    int total = 0, ans = 0;
    for (auto &i : v) cin >> i, total += i;
    for (int l = *max_element(all(v)), r = total+1; l < r;) {
        int m = l + ((r-l) >> 1), cnt = 0, sum = 0;
        // m 為 subarray sum 的上限
        for (auto &i : v) {
            if (sum + i > m) {
                sum = i;
                cnt++;
            }
            else sum += i;
        } cnt += sum > 0;
        if (cnt <= k) ans = r = m;
        else l = m+1;
    }
    cout << ans;
}