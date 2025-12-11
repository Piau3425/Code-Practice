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
    int x, y, z;
    cin >> x >> y >> z;
    z = max(0LL, z-min(x/3, y/2));
    cout << x*20+y*25+z*30 << '\n';
}