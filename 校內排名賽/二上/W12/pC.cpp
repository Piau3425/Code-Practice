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
    vector<int> v = {0, 1, 2, 2};
    for (int i = 4; i <= 76; i++) v.pb(v[i-2]+v[i-3]);
    for (int n; cin >> n; cout << v[n] << '\n');
}