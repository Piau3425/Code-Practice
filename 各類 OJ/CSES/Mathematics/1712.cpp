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

int p = 1e9+7;

int f(int n, int x, int m) {
    int ret = 1;
    for (; x; x>>=1, n = n*n%m) if (x&1) ret = ret*n%m;
    return ret;
}

signed main() { WA();
    int t;
    for (cin >> t; t--;) {
        int a, b, c; cin >> a >> b >> c;
        cout << f(a, f(b, c, p-1), p) << '\n';
    }
}