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
    int n, k, m, l, r, cnt;
    
    while (cin >> n >> k >> m, n+k+m) {
        l = -1; r = n;
        vector<int> v(n);
        iota(all(v), 0);
        cnt = 0;

        while (cnt < n) {
            for (int i = 0; i < k; i++) {
                l = (l+1)%n;
                while (v[l] == -1) l = (l+1)%n;
            }
            for (int i = 0; i < m; i++) {
                r = (r-1+n)%n;
                while (v[r] == -1) r = (r-1+n)%n;
            }
            
            if (l == r) {
                cout << setw(3) << v[l]+1;
                cnt++;
            }
            else {
                cout << setw(3) << v[l]+1 << setw(3) << v[r]+1;
                cnt += 2;
            }
            v[l] = -1; v[r] = -1;
            if (cnt < n) cout << ',';
        }
        cout << '\n';
    }
}