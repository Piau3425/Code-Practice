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
    map<string, vector<string>> mp;
    for (string s; cin >> s, s != "XXXXXX";) {
        string k = s; sort(all(k));
        mp[k].pb(s);
    }
    for (auto &i : mp) sort(all(i.se));
    for (string s; cin >> s, s != "XXXXXX";) {
        string k = s; sort(all(k));
        if (mp.count(k)) {
            for (auto &i : mp[k]) cout << i << '\n';
        }
        else cout << "NOT A VALID WORD\n";
        cout << "******\n";
    }
}