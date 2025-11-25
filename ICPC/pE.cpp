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
        string s, a, b; int n, m; cin >> s >> n >> m;
        a = b = s; n--, m--;
        while (n--) next_permutation(all(a));
        while (m--) next_permutation(all(b));
        int ca, cb; ca = cb = 0;
        for (auto &i : a) for (auto &j : b) if (i == j) cb++;
        for (int i = 0; i < s.size(); i++) if (a[i] == b[i]) ca++;
        cout << ca << 'A' << cb-ca << "B\n";
    }
}