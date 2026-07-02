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

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    int t; for (cin >> t, cin.ignore(), cin.ignore(); t--;) {
        vector<vector<PII>> v(100, vector<PII>(9, {-1, 0}));
        vector<int> g(100);
        string s; while (getline(cin, s) && s.size()) {
            stringstream ss(s);
            int uid, pid, time;
            ss >> uid >> pid >> time >> s;
            uid--, pid--;
            if (~v[uid][pid].fi) continue;
            if (s == "C") v[uid][pid].fi = v[uid][pid].se*20 + time;
            if (s == "I") v[uid][pid].se++;
            g[uid] = 1;
        }
        vector<tuple<int, int, int>> result;
        for (auto &i : v) {
            int cnt = 0, alltime = 0;
            for (auto &j : i) if (~j.fi) cnt++, alltime += j.fi;
            if (g[&i-v.data()]) result.pb({-cnt, alltime, &i-v.data()});
        }
        sort(all(result));
        for (auto &[mx, alltime, id] : result) cout << id+1 << ' ' << -mx << ' ' << alltime << '\n';
        if (t) cout << '\n';
    }
}