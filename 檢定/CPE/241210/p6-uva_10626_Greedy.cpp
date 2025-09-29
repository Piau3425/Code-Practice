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
    int t; cin >> t;
    while (t--) {
        int n, c1, c5, c10; cin >> n >> c1 >> c5 >> c10;
        if (c10 >= n) cout << n;
        else {
            n -= c10;
            if (c5 >= n*2) cout << c10 + 2*n;
            else if (c5 >= n) cout << c10 + 6*n - 2*c5; // c10 + 2*(c5-n) + 4*(n-(c5-n))
            else if (c10 >= n - c5) cout << c10 + 7*n - 3*c5; // 4*(c5) + 8*(n-c5)
            else cout << 8*n - 4*c5;
        }
        cout << '\n';
    }
}