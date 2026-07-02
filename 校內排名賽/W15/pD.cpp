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

map<string, int> stoidx;
int id;

int f(string s) {
    if (stoidx.count(s)) return stoidx[s];
    return stoidx[s] = id++;
}

signed main() { WA();
    for (int n; cin >> n, n;) {
        string s, e;
        int is, ie;
        stoidx.clear();
        id = 0;
        cin >> s >> e;
        is = f(s), ie = f(e);
        vector<vector<int>> w(n*2+5, vector<int>(27, INF));
        vector<vector<pair<int, string>>> v(n*2+5);
        while (n--) {
            string a, b, c; cin >> a >> b >> c;
            int ai = f(a), bi = f(b);
            v[ai].pb({bi, c});
            v[bi].pb({ai, c});
        }
        priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
        pq.push({0, is, 26}); w[is][26] = 0;

        while (pq.size()) {
            auto [nowDis, nowStr, nowChar] = pq.top(); pq.pop();

            if (nowDis > w[nowStr][nowChar]) continue;

            for (auto &[toStr, toDis] : v[nowStr]) {
                int toChar = toDis.front()-'a';
                if (toChar != nowChar && nowDis + toDis.size() < w[toStr][toChar]) {
                    w[toStr][toChar] = nowDis + toDis.size();
                    pq.push({w[toStr][toChar], toStr, toChar});
                }
            }
        }

        if (*min_element(all(w[ie])) == INF) cout << "impossivel\n";
        else cout << *min_element(all(w[ie])) << '\n';
    }
}