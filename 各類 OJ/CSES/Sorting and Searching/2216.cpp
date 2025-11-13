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
    int n; cin >> n; vector<int> v(n), pos(n);
    for (auto &i : v) cin >> i, pos[i-1] = &i-v.data();
    int cnt = 1;
    for (int i = 0; i+1 < n; i++) {
        if(pos[i+1] < pos[i]) cnt++;
        //cout << i+1+1 << ' ' << i+1 << ' ' << pos[i+1] << ' ' << pos[i] << '\n';
    }
    cout << cnt << '\n';
}