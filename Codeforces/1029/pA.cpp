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
    int t; cin >> t;
    while (t--) {
        int n, x, first, last; first = -1; last = 0; cin >> n >> x;
        for (int i = 0; i < n; i++)  {
            int p; cin >> p;
            if (!(~first) && p) first = i;
            if (p) last = i;
        }
        if (last-first+1 <= x) cout << "YES\n";
        else cout << "NO\n";
    }
}