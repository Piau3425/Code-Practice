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
    int n, m, c, ans = 0;
    cin >> n >> m >> c;
    vector<int> b(m);
    for (auto &i : b) cin >> i;
    while (n--) {
        int sum = 0;
        for (auto &i : b) {
            int a; cin >> a;
            sum += a*i;
        }
        if (sum + c > 0) ans++;
    }
    cout << ans;
}