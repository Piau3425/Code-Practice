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
    int t = 1, T; for (cin >> T; t <= T; t++) { cout << "Case #" << t << ": ";
        string ans;
        int n; cin >> n;
        do {
            ans = char(n%-2+'0') + ans;
            if (n%-2 == -1) ans.front() += 2, n = n/-2+1;
            else n /= -2;
        } while (n);
        cout << ans << '\n';
    }
}