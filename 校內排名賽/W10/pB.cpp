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
    // 2*k-1, 2*k-1-2, 2*k-1-2-2, 6*k-9
    for (int n; cin >> n;) cout << 6*(++n/2)*(n/2)-9 << '\n';
}