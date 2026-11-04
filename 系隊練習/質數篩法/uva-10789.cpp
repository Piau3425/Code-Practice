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

bool f(int n){ for (int i = 2; i*i <= n; i++) if (n%i == 0) return 0; return n>1; }

signed main() { WA();
    int n, t = 0; for (cin >> n; n--;) { cout << "Case " << ++t << ": ";
        string s; cin >> s;
        map<char, int> mp;
        for (auto &c : s) mp[c]++;
        int flag = 0;
        for (auto &[c, i] : mp) if(f(i)) cout << c, flag = 1;
        if (!flag) cout << "empty\n";
        else cout << '\n';
    }
}