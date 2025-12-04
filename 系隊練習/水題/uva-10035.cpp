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
    int a, b;
    while (cin >> a >> b, a+b) {
        int sum = 0, cnt = 0;
        while (a || b) {
            sum += a%10 + b%10;
            a /= 10, b /= 10;
            if (sum >= 10) cnt++;
            sum /= 10;
            //cout << a << ' ' << b << ' ' << cnt << '\n';
        }
        if (sum >= 10) cnt++;
        if (cnt) cout << cnt << " carry operation" << (cnt > 1 ? "s" : "") << ".\n";
        else cout << "No carry operation.\n";
    }
}