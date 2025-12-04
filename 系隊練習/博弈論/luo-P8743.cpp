#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n; cin >> n;
    while (n--) {
        int t, sum = 0, e; cin >> t;
        vector<int> bit(20);
        for (int i = t; i; i--) {
            cin >> e; sum ^= e;
            for (int j = 0; j < 20; j++) bit[j] += (e>>j)&1;
        }

        if (sum) {
            int i = 19;
            while (!(bit[i]&1)) i--;
            if (bit[i] == 1) cout << 1 << '\n';
            else if (t&1) cout << 1 << '\n';
            else cout << -1 << '\n';
        }
        else cout << 0 << '\n';
    }
}