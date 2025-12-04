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
    int n, a, b, c;
    while (cin >> n >> a >> b >> c, n||a||b||c) {
        int da, db, dc;
        if (a-n > 0) da = 40-abs(n-a); else da = (n-a);
        if (b-a > 0) db = b-a; else db = 40-abs(a-b);
        if (c-b > 0) dc = 40-abs(b-c); else dc = (b-c);
        if (a == n) da = 0; if (b == a) db = 0; if (c == b) dc = 0;
        cout << (da+db+dc+120)*9 << '\n';
    }
}