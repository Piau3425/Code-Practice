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
    int t; double cap, temp;
    cin >> t;
    while (t--) {
    	cin >> cap >> temp;
        int n; cin >> n;
        vector<PII> v(n);
        vector<double> a(n+1), b(n+1);
        for (auto &i : v) cin >> i.se >> i.fi, i.fi *= i.se;
        for (int i = 1; i <= n; i++) a[i] = a[i-1]+v[i-1].fi, b[i] = b[i-1]+v[i-1].se;

        PII ans;
        double mn = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                double u = a[j]-a[i-1], d = b[j]-b[i-1], dif = abs(u/d-temp);
                if (d > cap) break;
                if (dif <= 5 && dif < mn && d >= ceil(cap/2)) mn = dif, ans = {i-1, j-1}; // 考試時沒看到 d >= cap/2
            }
        }

        if (mn == INF) cout << "Not possible\n";
        else cout << ans.fi << ' ' << ans.se << '\n';
    }
}