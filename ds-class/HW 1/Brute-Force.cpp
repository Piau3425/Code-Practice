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
    int n, T = 0; while (scanf("%lld", &n), n) {
        printf("**********************************************************\nNetwork #%lld\n", ++T);
        int x, y;
        vector<pair<int, int>> v(n);
        for (auto &i : v) scanf("%lld %lld\n", &i.fi, &i.se);
        vector<int> order(n);
        iota(all(order), 0);
        double mn = 1e9;
        vector<int> ans;
        do {
            double len = 0;
            for (int i = 1; i < n; i++) {
                int now = order[i], prev = order[i-1];
                len += hypot(v[now].fi-v[prev].fi, v[now].se-v[prev].se) + 16;
            }
            if (len < mn) {
                ans = order;
                mn = len;
            }
        } while (next_permutation(all(order)));
        for (int i = 1; i < ans.size(); i++) printf("Cable requirement to connect (%lld,%lld) to (%lld,%lld) is %.2lf feet.\n", v[ans[i-1]].fi, v[ans[i-1]].se, v[ans[i]].fi, v[ans[i]].se, hypot(v[ans[i]].fi-v[ans[i-1]].fi, v[ans[i]].se-v[ans[i-1]].se)+16);
        printf("Number of feet of cable required is %.2lf.\n", mn);
    }
}