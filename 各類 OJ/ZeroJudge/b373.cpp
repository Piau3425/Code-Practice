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
    for (int n; cin >> n;) {
        vector<int> v(n); int cnt = 0;
        for (auto &i : v) cin >> i;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (v[j] > v[j+1]) swap(v[j], v[j+1]), cnt++;
            }
        }
        cout << cnt << '\n';
    }
}