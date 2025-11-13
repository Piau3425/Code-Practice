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

signed main() {
    int n, k; cin >> n >> k;
    int coin[] = {500, 100, 50, 10, 5, 1};
    int now = 1000-n*k;
    int cnt = 0;
    for (int i = 0, g = 100; i < 6; i++) {
        while (now>=coin[i]) {
            //cout << now << '\n';
            cnt++;
            now -= coin[i];
        }
    }
    cout << cnt << '\n';
}