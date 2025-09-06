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
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int ans = 0;
        for(int i = 1; i*i <= n; i++){
            if (!(n%i)) {
                ans++;
                if(i != n/i) ans++;
            } 
        }
        cout << ans << '\n';
    }
}