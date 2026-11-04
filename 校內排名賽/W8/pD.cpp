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

#define N 65536
signed main() { WA();
    vector<int> p(N, 1); p[0] = p[1] = 0;
    vector<int> v;
    vector<int> ans(N*2+50);
    for (int i = 2; i < N; i++) if (p[i]) {
        v.pb(i);
        for (int j = i*i; j < N; j+=i) p[j] = 0;
    }
    
    for (int i = 0; i < v.size(); i++) for (int j = i; j < v.size(); j++) ans[v[i]+v[j]]++;
    
    for (int n; cin >> n, n;) {
        cout << ans[n] << '\n';
    }
}