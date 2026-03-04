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

void euc(int a, int b, int &x, int &y) {
    if (!b) return x = 1, y = 0, void();
    euc(b, a%b, y, x);
    y -= a/b*x;
}

void solve(int a, int b) {
    int x, y;
    euc(a, b, x, y);
    cout << x << ' ' << y << ' ' << __gcd(a, b) << '\n';
}

signed main() { WA();
    for (int a, b; cin >> a >> b; solve(a, b));
}