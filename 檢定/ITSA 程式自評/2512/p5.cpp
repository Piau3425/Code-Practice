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

double sa, sb, cnta, cntb, ans, mn, cntmn;
int t;
vector<double> v;

void dfs(int x) {
    if (x == t) {
        if (abs(sa-sb) < mn || (abs(sa-sb) == mn && min(cnta, cntb) < ans)) {
            ans = min(cnta, cntb);
            mn = abs(sa-sb);
        }
        return;
    }
    sa += v[x]; cnta++;
    dfs(x+1);
    sa -= v[x]; cnta--;
    sb += v[x]; cntb++;
    dfs(x+1);
    sb -= v[x]; cntb--;
}

signed main() { WA();
    cin >> t;
    v.assign(t, 0);
    sa = sb = 0;
    ans = cntmn = mn = INF;
    for (auto &i : v) {
        int a, b; cin >> a >> b;
        i = a/b;
    }
    dfs(0);
    cout << mn << '\n' << ans << '\n';
}