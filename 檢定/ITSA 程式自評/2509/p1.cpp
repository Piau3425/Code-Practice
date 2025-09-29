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
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        if (a >= 60 || (b >= 60 && a+b+c > 240)) cout << "P\n";
        else if (b >= 60 || c >= 85) cout << "M\n";
        else cout << "F\n";
    }
}