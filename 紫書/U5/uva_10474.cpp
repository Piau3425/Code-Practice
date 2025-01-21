#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int a, b, loop = 1;
    while (cin >> a >> b, a&&b) {
        cout << "CASE# " << loop++ << ":\n";
        vector<int> v;
        int t;
        while (a--) {
            cin >> t;
            v.pb(t);
        }
        sort(all(v));
        while (b--) {
            cin >> t;
            if (*lower_bound(all(v), t) == t) cout << t << " found at " << lower_bound(all(v), t)-v.begin()+1 << '\n';
            else cout << t << " not found\n";
        }
    }
}