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

signed main() { WA();
    for (int n, m, a, b; cin >> n >> m, n+m;) {
        vector<vector<int>> v(n);
        vector<int> w(n, 0), ans;
        
        while (m--) {
            cin >> a >> b;
            v[--a].push_back(--b);
            w[b]++;
        }

        queue<int> q;
        
        for (int i = 0; i < n; i++) if (!w[i]) q.push(i);
        
        while (q.size()) {
            ans.pb(q.front());
            for (auto i : v[q.front()]) if (!(--w[i])) q.push(i);
            q.pop();
        }

        if (ans.size() == n) for (auto &i : ans) cout << 1+i << '\n';
        else cout << "IMPOSSIBLE\n";
    }
}