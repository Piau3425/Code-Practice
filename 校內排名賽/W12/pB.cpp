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
    int a, b, c, d, l;
    while (cin >> a >> b >> c >> d >> l, a+b+c+d+l) {
        int cnt = 0;
        for (int i = 0; i <= l; i++) {
            cnt += (a*i*i+b*i+c)%d == 0;
        }
        cout << cnt << '\n';
    }
}