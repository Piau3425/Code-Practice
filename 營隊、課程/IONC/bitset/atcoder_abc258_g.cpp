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
    int n; cin >> n;
    bitset<3001> b[3001];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            b[i][j] = c-'0';
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) if (b[i][j]) {
            ans += (b[i] & b[j]).count();
        }
    }
    cout << ans/3;
}