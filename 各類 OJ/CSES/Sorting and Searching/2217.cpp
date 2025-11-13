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

// v[第幾個] = 值
// pos[值] = 第幾個

signed main() { WA();
    int n, m; cin >> n >> m; vector<int> v(n), pos(n);
    for (auto &i : v) cin >> i, pos[i-1] = &i-v.data();
    for (int i = 0; i < n; i++) pos[v[i]-1] = i;
    while (m--) {
        int a, b; cin >> a >> b; a--, b--;
        swap(pos[v[a]-1], pos[v[b]-1]);
        int cnt = 1;
        for (int i = 0; i+1 < n; i++) if (pos[i+1] < pos[i]) cnt++;
        cout << cnt << '\n';
    }
}