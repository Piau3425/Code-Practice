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
    int t; for (cin >> t; t--;) {
        int n; cin >> n;
        vector<int> v(n), b(n-1);
        for (auto &i : v) cin >> i;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (v[i] <= v[j]) b[j-1]++;
            }
        }
        int sum = 0;
        for (auto &i : b) sum += i; //, cout << i << ' ';
        cout << sum << '\n';
    }
}