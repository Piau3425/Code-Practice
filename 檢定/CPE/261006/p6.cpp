#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIII tuple<int, int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

map<string, int> mp;
vector<string> name;
int id;

int gid(string s) {
    if (mp.count(s)) return mp[s];
    name.pb(s);
    return mp[s] = id++;
}

signed main() { WA();
    int t = 1, T; for (cin >> T; t <= T; t++) { cout << (t-1 ? "\n" : "") << "Map #" << t << '\n';
        mp.clear(); id = 0; name.clear();
        int n; cin >> n;
        vector<vector<PII>> v(n);
        vector<int> p(n);
        for (auto &i : p) {
            string s; int k; cin >> s >> k;
            p[gid(s)] = k;
        }
        int m; for (cin >> m; m--;) {
            string a, b; int k; cin >> a >> b >> k;
            int na = gid(a), nb = gid(b);
            v[na].pb({nb, k});
            v[nb].pb({na, k});
        }
        map<int, vector<int>> mp, path;
        int q = 1, qq; for (cin >> qq; q <= qq; q++) { cout << "Query #" << q << '\n';
            string a, b; int k; cin >> a >> b >> k;
            int na = gid(a), nb = gid(b);
            if (!mp.count(na)) {
                vector<int> &dis = mp[na], &prev = path[na]; dis.assign(n, INF); prev.assign(n, -1);
                priority_queue<PII, vector<PII>, greater<PII>> pq;
                pq.push({p[na], na}); dis[na] = p[na];
                while (pq.size()) {
                    int nd, n; tie(nd, n) = pq.top(); pq.pop();
                    if (nd > dis[n]) continue;
                    for (auto &i : v[n]) {
                        int tod, to; tie(to, tod) = i;
                        if (dis[n] + 2*tod + p[to] < dis[to]) {
                            pq.push({dis[to] = dis[n]+2*tod+p[to], to});
                            prev[to] = n;
                        }
                    }
                }
            }

            vector<int> g;
            for (int i = nb; i != na; i = path[na][i]) g.pb(i); g.pb(na);
            reverse(all(g));
            for (auto &i : g) cout << name[i] << " \n"[&i == &g.back()];

            cout << "Each passenger has to pay : " << fixed << setprecision(2) << 1.1*mp[na][nb]/k << " taka\n";
        }
    }
}