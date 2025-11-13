#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se sec
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        if (!((a+b)%3) && a*2 >= b) cout << "YES\n";
        else cout << "NO\n";
    }
}