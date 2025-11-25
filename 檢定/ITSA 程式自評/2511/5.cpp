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

int C(int m, int n) {
    int ret = 1;
    for (int i = 1; i <= n; ++i) ret = ret*(m-i+1)/i;
    return ret;
}

signed main() { WA();
    int m; cin >> m;
    int k = C(m, 6);
    cout << k << '\n' << k*50 << '\n' << fixed << setprecision(2) << (double)k/C(49, 6)*100 << "%\n";
}