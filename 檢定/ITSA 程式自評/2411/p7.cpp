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
    int n, cost = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    while (v.size() > 1) {
        int mn = INF, idx;
        for (int i = 0; i+1 < v.size(); i++) if (max(v[i], v[i+1]) < mn) {
            mn = max(v[i], v[i+1]);
            idx = (v[i] < v[i+1] ? i : i+1);
        }
        cost += mn;
        v.erase(v.begin() + idx);
    }
    cout << cost;
}