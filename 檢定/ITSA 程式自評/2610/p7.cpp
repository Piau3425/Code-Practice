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

vector<vector<int>> v;
vector<int> dis, path;
int n, s, t;

void dfs(int x) {
    if (x == t) {
        for (auto &i : path) cout << i+1 << ",\n"[&i == &path.back()];
        return;
    }

    for (int i = 0; i < n; i++) if (v[x][i] && dis[x]-1 == dis[i]) {
        path.pb(i);
        dfs(i);
        path.pop_back();
    }
}

signed main() { WA();
    char k;
    cin >> n >> k >> s >> k >> t; s--, t--;
    v.assign(n, vector<int>(n));
    dis.assign(n, INF);
    for (auto &i : v) for (auto &j : i) cin >> j;
    queue<PII> q; q.push({t, 0});
    
    while (q.size()) {
        int now, step;
        tie(now, step) = q.front(); q.pop();
        if (dis[now] <= step) continue;
        dis[now] = step;
        for (int i = 0; i < n; i++) if (v[now][i]) {
            q.push({i, step+1});
        }
    }

    path.pb(s), dfs(s);
}