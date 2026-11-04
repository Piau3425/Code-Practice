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
    int t; for (cin >> t; t--;) {
        vector<set<char>> v(5);
        char c; for (int i = 0; i < 4; i++) {
            cin >> c;
            int n; while (cin >> n, n) {
                v[n].insert(c);
            }
        }

        vector<string> ans;
        string s = "1234";
        do {
            int flag = 1;
            for (int i = 0; i < 4; i++) {
                char c = s[i];
                if (v[c-'0'].count('A'+i)) flag = 0;
            }
            if (flag) ans.pb(s);
        } while (next_permutation(all(s)));
        if (ans.size()) {
            cout << "ABCD\n";
            sort(all(ans));
            for (auto &s : ans) cout << s << '\n';
        }
        else cout << "No Solution\n";
        if (t) cout << '\n';
    }
}