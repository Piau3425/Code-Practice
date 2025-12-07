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
    int n; cin >> n;
    vector<PII> v(n);
    for (auto &i : v) cin >> i.fi >> i.se;
    sort(all(v), [](PII a, PII b){
        if (a.se == b.se) return a.fi > b.fi;
        return a.se < b.se;
    });
    int now, cnt; now = cnt = 0;
    for (auto &[sta, ed] : v) {
        if (now < sta) now = ed;
        cnt++;
    }
    
}