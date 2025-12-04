#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
//#define int long long
#define PII pair<int, int>

signed main() { WA();
    double a, b, c;
    int dd;
    while (1) {
        cin >> a >> b >> c >> dd;
        cout << fixed << setprecision(2) << b/a*41.2 << ' ' << a*b/634.4+(c > 30)*int(c-30)/5*0.15 << ' ' << b*0.4+(c > 28)*int(c-28)/2*0.25 << '\n';
        if (dd) break;
    }
}