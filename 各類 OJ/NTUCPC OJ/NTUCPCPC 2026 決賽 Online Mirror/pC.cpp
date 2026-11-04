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

inline bool wall(char c) {
    return c != '.' && c != '*' && c != ',';
}

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<string> v(n); for (auto &i : v) cin >> i;
    int ok = 1;

    auto sweep = [&](int d) {
        vector<char> cnt(m, 0);
        for (int i = (d > 0 ? 0 : n-1); i >= 0 && i < n; i += d) {
            char k = 0;
            for (int j = (d > 0 ? 0 : m-1); j >= 0 && j < m; j += d) {
                char &c = v[i][j];
                if (wall(c)) { k = cnt[j] = 0; continue; }
                if (c == '*') {
                    if (k || cnt[j]) ok = 0;
                    k = cnt[j] = 1;
                }
                else if (k || cnt[j]) c = ',';
            }
        }
    };

    sweep(1), sweep(-1);
    for (int i = 0; i < n && ok; i++) for (int j = 0; j < m; j++) {
        char c = v[i][j];
        if (c == '.') { ok = 0; break; }
        if (c >= '0' && c <= '4') {
            int e = (i && v[i-1][j] == '*') + (i+1 < n && v[i+1][j] == '*') + (j && v[i][j-1] == '*') + (j+1 < m && v[i][j+1] == '*');
            if (e != c-'0') { ok = 0; break; }
        }
    }
    if (ok) cout << "!!\n";
    else cout << "??\n";
}