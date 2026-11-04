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
#define SZ(x) ((int)(x).size())

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int max_rectangle(vector<int> s) {
    stack<PII> st; st.push({-1, 0});
    s.pb(0);
    int ans = 0;
    for (int i = 0; i < SZ(s); i++) {
        PII now = {s[i], i};
        while (s[i] < st.top().fi) {
            now = st.top(); st.pop();
            ans = max(ans, (i - now.se) * now.fi);
        }
        if (s[i] > st.top().fi) st.push({s[i], now.se});
    }
    return ans;
}

signed main() { WA();
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    cout << max_rectangle(v) << '\n';
}