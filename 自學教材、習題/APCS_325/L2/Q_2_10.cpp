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

void rec(vector<int> &v, set<int> &st, int idx, int sum) {
    if (idx == v.size()) return void(st.insert(sum));

    rec(v, st, idx+1, sum + v[idx]);
    rec(v, st, idx+1, sum);
}

signed main() { WA();
    int n, p;
    cin >> n >> p;
    vector<int> a(n/2), b(n/2+(n&1));
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    set<int> sa, sb;
    rec(a, sa, 0, 0);
    rec(b, sb, 0, 0) ;
    int mx = -1e9;
    // for (auto &i : sa) cout << i << ' '; cout << '\n'; for (auto &i : sb) cout << i << ' '; return 0;
    for (auto &i : sa) {
        auto it = sb.lower_bound(p-i);
        if (*it != p-i) mx = max(mx, *prev(it)+i);
        else {
            mx = p;
            break;
        }
    }
    cout << mx;
}