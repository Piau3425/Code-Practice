#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, m; cin >> n >> m;
    int x;
    multiset<int> a; while (n--) {
        cin >> x; a.insert(x);
    }
    while (m--) {
        cin >> x;
        if (auto it = a.upper_bound(x); it != a.begin()) cout << *prev(it) << '\n', a.erase(prev(it));
        else cout << "-1\n";
    }

}