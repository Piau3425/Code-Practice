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

vector<int> anc;

int Find(int x) {
    return x == anc[x] ? x : anc[x] = Find(anc[x]);
}

void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if (a > b) swap(a, b);
    anc[b] = a;
}

signed main() { WA();
    int n, T = 0; while (scanf("%lld", &n), n) {
        printf("**********************************************************\nNetwork #%lld\n", ++T);
        int x, y;
        vector<pair<int, int>> v(n);
        for (auto &i : v) scanf("%lld %lld\n", &i.fi, &i.se);
        double len = 0;
        vector<tuple<double, int, int>> g;
        int n = v.size();
        vector<int> deg(n);
        anc.assign(n, 0);
        iota(all(anc), 0);
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++)
            g.pb({hypot(v[i].fi-v[j].fi, v[i].se-v[j].se), i, j});
        sort(all(g));
        vector<vector<int>> path(n);
        for (auto &[w, a, b] : g) {
            if (Find(a) != Find(b) && deg[a] <= 1 && deg[b] <= 1) {
                Union(a, b);
                deg[a]++; deg[b]++;
                len += w+16;
                path[a].pb(b);
                path[b].pb(a);
            }
        }
        int now, prev = -1;
        for (auto &i : deg) if (i == 1) {
            now = &i-deg.data();
            break;
        }
        vector<int> ans;
        while (~now) {
            ans.pb(now);
            int next = -1;
            for (auto &i : path[now]) if (i != prev) {
                next = i; break;
            }
            prev = now;
            now = next;
        }

        for (int i = 1; i < ans.size(); i++) printf("Cable requirement to connect (%lld,%lld) to (%lld,%lld) is %.2lf feet.\n", v[ans[i-1]].fi, v[ans[i-1]].se, v[ans[i]].fi, v[ans[i]].se, hypot(v[ans[i]].fi-v[ans[i-1]].fi, v[ans[i]].se-v[ans[i-1]].se)+16);
        printf("Number of feet of cable required is %.2lf.\n", len);
    }
}