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
    int x[] = {1, 5, 10, 50};
    int n; cin >> n;
    while (n--) {
        int k, ans = 0; cin >> k;
        for (int i = 3; i+1; i--) while (k/x[i]) k -= x[i], ans++;
        cout << ans << '\n';
    }
}