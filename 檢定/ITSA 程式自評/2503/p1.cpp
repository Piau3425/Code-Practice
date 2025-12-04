#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int t, n, sum = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 10) cout << 50*n << '\n';
        else if (n < 30) cout << 50*0.9*n << '\n';
        else cout << 50*0.7*n << '\n';
    }
}