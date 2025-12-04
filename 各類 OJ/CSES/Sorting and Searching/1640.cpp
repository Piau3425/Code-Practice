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
    int n, x, t, i = 1;
    cin >> n >> x;

    map<int, int> mp;
    while (n--) {
        cin >> t;
        if (mp[x-t]) return cout << mp[x-t] << ' ' << i, 0;
        else mp[t] = i++;
    }
    cout << "IMPOSSIBLE";
}