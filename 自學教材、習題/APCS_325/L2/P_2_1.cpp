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
    set<int> st;
    int n, k; cin >> n;
    while (n--) cin >> k, st.insert(k);
    cout << st.size() << '\n';
    for (auto &i : st) cout << i << ' ';
}