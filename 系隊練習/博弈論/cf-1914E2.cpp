#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int n, ans = 0; cin >> n;
        vector<int> a(n), b(n);
        vector<PII> sum(n); // {權重 (a[i] + b[i])、彈珠顏色}
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        for (int i = 0; i < n; i++) sum[i] = {a[i] + b[i], i}; // 數字總和越大代表影響越大 (一正一負造成的分數差)
        sort(all(sum), greater<PII>()); // 由大到小排序
        for (int i = 0; i < n; i++) {
            if (!(i&1)) ans += a[sum[i].se]-1; // Alice 先手，挑選影響最大，分數加上 (彈珠數量 + 1)
            else ans -= b[sum[i].se]-1; // Bob 後手，挑選剩餘的影響最大，分數減去 (彈珠數量 - 1)
        }
        cout << ans << '\n';
    }
}