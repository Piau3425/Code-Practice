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

signed main() { WA();
    int t = 1, T; for (cin >> T; t <= T; t++) { cout << "Case #" << t << ":\n";
        string s; cin >> s;
        int now = 0, mx = -1e9, mn = 1e9;
        for (auto &c : s) {
            int k;
            if (c == 'R') k = now++;
            if (c == 'F') k = --now;
            if (c == 'C') k = now;
            mx = max(mx, k), mn = min(mn, k);
        }
        vector<vector<char>> v(mx-mn+2, vector<char>(s.size()+3, ' '));
        for (auto &i : v) i[0] = '|';
        for (auto &i : v.back()) i = '-'; v.back().front() = '+';
        
        now = 0;
        for (int i = 2; i < s.size()+2; i++) {
            if (s[i-2] == 'R') v[mx-now++][i] = '/';
            else if (s[i-2] == 'F') v[mx-(--now)][i] = '\\';
            else v[mx-now][i] = '_';
        }

        for (auto &i : v) {
            int len = i.size()-1;
            while (i[len] == ' ') len--;
            for (int j = 0; j <= len; j++) cout << i[j];
            cout << '\n';
        }
        cout << '\n';
    }
}