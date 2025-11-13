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
    int n, m, k; cin >> n >> m >> k;
    deque<int> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    sort(all(a)); sort(all(b));
    int cnt = 0;
    for (int adx = 0, bdx = 0; adx < n && bdx < m;) {
        if (b[bdx]+k < a[adx]) bdx++;
        else if (b[bdx]-k > a[adx]) adx++;
        else adx++, bdx++, cnt++;
    }
    cout << cnt << '\n';
}