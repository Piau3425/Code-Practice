#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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