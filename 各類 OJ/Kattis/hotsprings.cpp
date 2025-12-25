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
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(all(v));
    //for (auto &i : v) cout << i << ' '; cout << '\n';
    int l = n/2-1, r = n/2;
    deque<int> ans;
    while (l >= 0 && r < n) ans.push_front(v[r++]), ans.push_front(v[l--]);
    while (l >= 0) ans.push_front(v[l--]);
    while (r < n) ans.push_front(v[r++]);
    for (auto &i : vector<int>(ans.rbegin(), ans.rend())) cout << i << ' ';
}