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
    int t; for (cin >> t; t--;) {
        int k, ans = 1; string s;
        cin >> k >> s;
        for (int i = 0; i < k; i++) if (s[i] != s[(i+1)%k]) ans++;
        cout << min(k, ans) << '\n';
    }
}