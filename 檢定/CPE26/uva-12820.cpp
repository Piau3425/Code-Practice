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
    for (int n, cas = 0; cin >> n;) {
        string s; int cnt = 0;
        while (n--) {
            cin >> s;
            map<char, int> mp;
            for (auto &c : s) mp[c]++;
            set<int> st; for (auto &[a, b] : mp) st.insert(b);
            cnt += mp.size() == st.size() && mp.size() > 1;
        }
        cout << "Case " << ++cas << ": " << cnt << '\n';
    }
}