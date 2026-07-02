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

int H(int n) {
    int res = 0, sn = sqrt(n);
    for (int i = 1; i <= sn; i++) res += n/i;
    return 2*res - sn*sn;
}

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n; cin >> n;
        cout << H(n) << '\n';
    }
}