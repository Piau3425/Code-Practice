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

int f(int n, int m) {
    if (n == 1) return 0;
    return (f(n-1, m)+m) %n;
}

signed main() { WA();
    for (int n; cin >> n, n;) {
        for (int i = 1; i < n; i++) {
            if (f(n-1, i) == 11) {
                cout << i << '\n';
                break;
            }
        }
    }
}