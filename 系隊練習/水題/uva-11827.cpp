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
    int n; cin >> n; cin.ignore();
    while (n--) {
        vector<int> v;
        int x;
        string s; getline(cin, s);
        stringstream ss(s);
        while (ss >> x) v.pb(x);
        int mx = -1e9;
        for (auto &i : v) for (auto &j : v) if (&i-&v.back() != &j-&v.back()) mx = max(mx, __gcd(i, j));
        cout << mx << '\n';
    }
}