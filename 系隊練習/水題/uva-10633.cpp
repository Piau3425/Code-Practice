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
    int n;
    while (cin >> n, n) {
        if (n%9) cout << n/9*10 + n%9 << '\n';
        else cout << n/9*10 - 1 << ' ' << n/9*10 << '\n';
    }
}