#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, len;
    cin >> n >> len;
    vector<PII> v(n);
    deque<int> qmx, qmn;
    for (auto &i : v) cin >> i.fi;
    for (auto &i : v) cin >> i.se;
    sort(all(v));
    int ans = -1e9;
    for (int l = 0, r = 0; r < n; r++) {
        while (qmx.size() && v[qmx.back()].se <= v[r].se) qmx.pop_back(); qmx.push_back(r);
        while (qmn.size() && v[qmn.back()].se >= v[r].se) qmn.pop_back(); qmn.push_back(r);
        while (v[r].fi - v[l].fi > len) {
            while (qmx.size() && qmx.front() <= l) qmx.pop_front();
            while (qmn.size() && qmn.front() <= l) qmn.pop_front();
            l++;
        }
        ans = max(ans, v[qmx.front()].se-v[qmn.front()].se);
    }
    cout << ans;
}