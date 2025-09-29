#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int n, last = -1, k = 0; cin >> n;
        vector<int> v(n);
        for (auto &i : v) {
            cin >> i;
            if (i == 0 && last == 0) k = 1;
            last = i;
        }
        cout << (k || *min_element(all(v)) ? "YES" : "NO") << '\n';
    }
}