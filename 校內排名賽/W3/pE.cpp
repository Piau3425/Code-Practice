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
    for (int t = (cin >> t, t); t--;) {
        int n, sum = 0; cin >> n;
        for (int i = 1; i < n; i++) if (!(n%i)) sum += i;
        if (sum > n) cout << "abundant\n";
        else if (sum < n) cout << "deficient\n";
        else cout << "perfect\n";
    }       
}