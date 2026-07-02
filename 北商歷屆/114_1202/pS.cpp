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

vector<int> anc;

int Find(int x) {
    return x == anc[x] ? x : anc[x] = Find(anc[x]);
}

bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a > b) swap(a, b);
    if (a == b) return false;
    return anc[a] = b, true;
}

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int m, n; cin >> m >> n;
        anc.resize(m); iota(all(anc), 0);
        vector<tuple<int, int, int>> v(n);
        int sum = 0;
        for (auto &[a, b, c] : v) cin >> b >> c >> a, sum += a;
        sort(all(v));
        int con = 0;
        for (auto &[a, b, c] : v) if (Union(b, c)) con += a;
        cout << sum - con << '\n';
    }
}