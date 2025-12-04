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
    vector<int> cnt(1000001);
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 1; i*j <= 1000000; j++) cnt[i*j]++;
    }
    int t;
    for (cin >> t; t--;) {
        int x; cin >> x;
        cout << cnt[x] << '\n';
    }
}