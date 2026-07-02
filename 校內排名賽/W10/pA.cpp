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
    int t; for (cin >> t; t--;) {
        vector<int> v(4);
        for (auto &i : v) cin >> i;
        sort(all(v));
        if (v[3] > v[0] + v[1] + v[2]) cout << "banana\n";
        else if ((v[0]+v[1]+v[2]+v[3])*1.0/4 == v[0]) cout << "square\n";
        else if (v[0] == v[1] && v[2] == v[3]) cout << "rectangle\n";
        else cout << "quadrangle\n";
    }
}