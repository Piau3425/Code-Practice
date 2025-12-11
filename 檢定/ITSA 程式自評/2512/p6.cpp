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

int f(int x) {
    if (x == 1) return 1;
    return x*f(x-1);
}

signed main() { WA();
    int x, y, z; cin >> x >> y >> z;
    cout << f(x+y)*(f(x+y)/f(x+y-z));
}