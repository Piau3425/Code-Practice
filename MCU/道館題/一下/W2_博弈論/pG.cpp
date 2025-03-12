#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        for (int k = 1; k <= n; k++) {
            int cnt = 0;
            vector<int> a(v);
            for (int i = 0; i < k; i++) {
                for (auto i : a) cout << i << ' ';
                cout << '\n';
                for (int j = 0; j < k; j++) if (v[i] < v[j]) {
                    swap(v[i], v[j]);
                    cnt++;
                }
            }
            //cout << (k-1 ? " " : "") << cnt;
        }
        cout << '\n';
    }
}