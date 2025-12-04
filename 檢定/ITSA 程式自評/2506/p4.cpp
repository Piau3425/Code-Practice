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
    int n; cin >> n;
    for (int s = 0; s <= n/50; s++) {
        for (int a = 0; a <= (n-50*s)/10; a++) {
            for (int b = 0; b <= (n-50*s-10*a)/5; b++) {
                for (int c = 0; c <= n-50*s-10*a-5*b; c++) {
                    if (s*50+a*10+b*5+c == n) cout << s << ' ' << a << ' ' << b << ' ' << c << '\n';
                }
            }
        }
    }
}