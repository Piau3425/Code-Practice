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
    int t, T = 1; for (cin >> t; T <= t; T++) {
        cout << "Pair #" << T << ": ";
        string a, b; cin >> a >> b;
        if (__gcd(stoi(a, 0, 2), stoi(b, 0, 2)) != 1) cout << "All you need is love!\n";
        else cout << "Love is not all you need!\n";
    }
}