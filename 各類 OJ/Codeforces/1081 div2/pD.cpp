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
#define MAXN 200005

int n;
vector<vector<int>> adj;
vector<int> a, dep, pa, SumA, SumADep, InMax, son, D1, D2, ansDel;

struct Line {
    int m, c;
    inline int eval(int x) { return m*x + c; }
};

inline bool bad(Line L1, Line L2, Line L3) {
    return (__int128_t)(L2.c - L1.c) * (L2.m - L3.m) <= (__int128_t)(L3.c - L2.c) * (L1.m - L2.m);
}

struct SegNode {
    vector<Line> hull;
    int lazy, maxVal;
} seg[MAXN<<2|1];

inline void push_up(int id) {
    seg[id].maxVal = max(seg[id<<1].maxVal, seg[id<<1|1].maxVal);
}

inline void apply(int id, int x) {
    seg[id].lazy = x;
    int l = 0, r = seg[id].hull.size() - 1, ans = 0;

    while (l <= r) {
        int m = (l+r) >> 1;
        if (!m || seg[id].hull[m].c - seg[id].hull[m-1].c >= x * (seg[id].hull[m-1].m - seg[id].hull[m].m)) ans = m, l = m+1;
        else r = m-1;
    }
    seg[id].maxVal = max(seg[id].maxVal, seg[id].hull[ans].eval(x));
}

inline void push_down(int id) {
    if (~seg[id].lazy) {
        apply(id<<1, seg[id].lazy);
        apply(id<<1|1, seg[id].lazy);
        seg[id].lazy = -1;
    }
}

void build_seg(int id, int l, int r, const vector<Line> &lines) {
    seg[id].lazy = -1; seg[id].maxVal = -INF; seg[id].hull.clear();

    for (int i = l; i <= r; i++) {
        Line lNew = lines[i];
        if (seg[id].hull.size() && seg[id].hull.back().m == lNew.m) {
            if (lNew.c <= seg[id].hull.back().c) continue;
            else seg[id].hull.pop_back();
        }
        while (seg[id].hull.size() >= 2 && bad(seg[id].hull[seg[id].hull.size()-2], seg[id].hull.back(), lNew))
            seg[id].hull.pop_back();
        seg[id].hull.pb(lNew);
    }
    if (l == r) return;
    int m = (l+r) >> 1;
    build_seg(id<<1, l, m, lines);
    build_seg(id<<1|1, m+1, r, lines);
}

void update_seg(int id, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) return void(apply(id, x));
    push_down(id); int m = (l+r) >> 1;
    if (ql <= m) update_seg(id<<1, l, m, ql, qr, x);
    if (qr > m) update_seg(id<<1|1, m+1, r, ql, qr, x);
    push_up(id);
}

int query_seg(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[id].maxVal;
    push_down(id); int m = (l+r) >> 1, res = -INF;
    if (ql <= m) res = max(res, query_seg(id<<1, l, m, ql, qr));
    if (qr > m) res = max(res, query_seg(id<<1|1, m+1, r, ql, qr));
    return res;
}

void dfs_init(int u, int p) {
    pa[u] = p; SumA[u] = a[u]; SumADep[u] = a[u] * dep[u];
    for (auto c : adj[u]) if (c != p) {
        dep[c] = dep[u] + 1; dfs_init(c, u);
        SumA[u] += SumA[c]; SumADep[u] += SumADep[c];
    }
}

void dfs_max(int u) {
    InMax[u] = dep[u];
    for (auto c : adj[u]) if (c != pa[u]) dfs_max(c), InMax[u] = max(InMax[u], InMax[c]);
    int mx = -1, mx2 = -1, bestC = 0, cnt = 0;
    for (auto c : adj[u]) if (c != pa[u]) {
        if (InMax[c] > mx) mx2 = mx, mx = InMax[c], bestC = c, cnt = 1;
        else if (InMax[c] == mx) cnt++;
        else if (InMax[c] > mx2) mx2 = InMax[c];
    }
    if (cnt > 1) mx2 = mx, bestC = 0;
    son[u] = bestC; D1[u] = ~mx ? mx : dep[u]; D2[u] = ~mx2 ? mx2 : dep[u];
}

int get_max_light(int u, int M) {
    int res = SumA[u] * (M - dep[u] + 1);
    for (auto c : adj[u]) if (c != pa[u]) res = max(res, get_max_light(c, M));
    return res;
}

void dfs_heavy(int u) {
    vector<int> path; int curr = u;
    while (curr) path.pb(curr), curr = son[curr];
    int K = path.size(), M = D1[path.back()];
    vector<int> maxLight(K+1, -INF), sufLight(K+2, -INF);

    for (int i = 1; i <= K; i++) {
        int vi = path[i-1];
        for (auto c : adj[vi]) if (c != pa[vi] && c != son[vi])
            maxLight[i] = max(maxLight[i], get_max_light(c, M));
    }
    for (int i = K; i; i--) sufLight[i] = max(sufLight[i+1], maxLight[i]);

    if (K > 1) {
        vector<Line> lines(K+1);
        for (int j = 2; j <= K; j++) lines[j] = {SumA[path[j-1]], SumA[path[j-1]] * (1 - dep[path[j-1]])};
        build_seg(1, 2, K, lines);
        vector<int> A(K+1), stk;
        for (int m = 1; m < K; m++) A[m] = D2[path[m-1]];

        for (int i = K-1; i; i--) {
            while (stk.size() && A[i] >= A[stk.back()]) stk.pop_back();
            update_seg(1, 2, K, i+1, stk.size() ? stk.back() : K, A[i]);
            stk.pb(i);
            ansDel[path[i-1]] = max(0LL, max(sufLight[i], query_seg(1, 2, K, i+1, K)));
        }
    }
    ansDel[path.back()] = max(0LL, sufLight[K]);
    for (auto x : path) for (auto c : adj[x]) if (c != pa[x] && c != son[x]) dfs_heavy(c);
}

void solve() {
    cin >> n;
    adj.assign(n+1, {}); a.assign(n+1, 0); dep.assign(n+1, 0); pa.assign(n+1, 0);
    SumA.assign(n+1, 0); SumADep.assign(n+1, 0); InMax.assign(n+1, 0);
    son.assign(n+1, 0); D1.assign(n+1, 0); D2.assign(n+1, 0); ansDel.assign(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    dep[1] = 0; dfs_init(1, 0); dfs_max(1); dfs_heavy(1);
    for (int i = 1; i <= n; i++) cout << SumADep[i] - dep[i]*SumA[i] + ansDel[i] << " \n"[i == n];
}

signed main() { WA();
    int t; for (cin >> t; t--;) solve();
}