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
    int n, m, a, b;
    while (cin >> n >> m, n != 1 || m != 1) {
        string ans;
        a = b = 1;
        PII left = {0, 1}, right = {1, 0};
        while (1) {
            if (n*b < a*m) {
                ans += "L";
                right = {a, b};
                a += left.fi, b += left.se;
            }
            else if (n*b > a*m) {
                ans += "R";
                left = {a, b};
                a += right.fi, b += right.se;                
            }
            else break;
        }
        cout << ans << '\n';
    }
}