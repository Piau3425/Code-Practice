#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n, xr = 0;
    cin >> n;
    vector<int> v(n-1);
    for (auto &i : v) cin >> i;
    for (int i = 0; i < n-1; i++) {
        xr ^= v[i]; xr ^= i+1;
    }
    xr ^= n;
    cout << xr;
}