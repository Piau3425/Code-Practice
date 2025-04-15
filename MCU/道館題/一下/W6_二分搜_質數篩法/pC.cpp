#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    cin >> n;
    sort(all(v));
    while (n--) {
        int t; cin >> t;
        auto it = lower_bound(all(v), t);
        if (it == v.end()) cout << v.back() << '\n';
        else if (it == v.begin()) cout << v.front() << '\n';
        else if (*it == t) cout << t << '\n';
        else if (abs(*it-t) < abs(*prev(it)-t)) cout << *it << '\n';
        else cout << *prev(it) << '\n'; 
    }
}