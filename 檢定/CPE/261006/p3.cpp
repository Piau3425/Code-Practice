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
    for (int n; cin >> n, n;) {
        queue<int> q;
        for (int i = 1; i <= n; i++) q.push(i);
        vector<int> ans;
        while (q.size() > 1) {
            ans.pb(q.front()); q.pop();
            q.push(q.front()); q.pop();
        }
        cout << "Discarded cards:";
        for (int i = 0; i < ans.size(); i++) cout << (i ? ", " : " ") << ans[i];
        cout << "\nRemaining card: " << q.front() << '\n';
    }
}