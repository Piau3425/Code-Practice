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
    vector<vector<int>> g(26);
    vector<int> cnt(26, -1);
    vector<string> v; for (string s; cin >> s, s != "#";) {
        v.pb(s);
        for (auto &c : s) cnt[c-'A'] = 0;
    }
    for (int i = 0; i+1 < v.size(); i++) {
        string &a = v[i], &b = v[i+1];
        for (int j = 0; j < min(a.size(), b.size()); j++) {
            if (a[j] != b[j]) {
                g[a[j]-'A'].pb(b[j]-'A');
                cnt[b[j]-'A']++;
                break;
            }
        }
    }

    string s;
    queue<int> q; for (auto &i : cnt) if (!i) q.push(&i-cnt.data());
    while (q.size()) {
        s += q.front()+'A';
        for (auto &i : g[q.front()]) if (!--cnt[i]) q.push(i);
        q.pop();
    }
    cout << s << '\n';
}