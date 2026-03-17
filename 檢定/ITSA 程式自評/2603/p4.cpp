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

struct Node {
    string s;
    int l, r, val;
    Node(string _s, int _l, int _r, int _v) : s(_s), l(_l), r(_r), val(_v) {}
};

int n, mx = -1;
vector<Node> v;
vector<string> ans;

void dfs(int idx, int pre, int sum, vector<string> path) {
    if (idx == n) {
        if (sum > mx) mx = sum, ans = path;
        return;
    }
    
    if (v[idx].l >= pre) {
        path.pb(v[idx].s);
        dfs(idx+1, v[idx].r, sum+v[idx].val, path);
        path.pop_back();
    }

    dfs(idx+1, pre, sum, path);
}

signed main() { WA();
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s; int l, r, m;
        cin >> s >> l >> r >> m;
        v.pb({s, l, r, m});
    }

    sort(all(v), [](Node a, Node b) {
        return a.l < b.l;
    });

    dfs(0, 700, 0, vector<string>());
    for (auto &i : ans) cout << i << " ";
    cout << mx << '\n';
}