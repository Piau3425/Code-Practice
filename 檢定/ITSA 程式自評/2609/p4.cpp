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
#define task tuple<int, int, int, string>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    priority_queue<task> pq;
    int now = 0;
    int cmd; for (; cin >> cmd;) {
        if (cmd == 1) {
            if (pq.empty()) {
                cout << "the CPU is no program\n";
                continue;
            }
            string s;
            int p, n, t;
            tie(p, n, t, s) = pq.top(); pq.pop();
            cout << s << " finished at time " << now+t << '\n';
            now += t;
        }
        else if (cmd == 2) {
            string name;
            int p, t; cin >> name >> p >> t;
            pq.push({-p, now, t, name});
        }
        else {
            while (pq.size()) {
                string s;
                int p, n, t;
                tie(p, n, t, s) = pq.top(); pq.pop();
                cout << s << " finished at time " << now+t << '\n';
                now += t;
            }
        }
    }
}