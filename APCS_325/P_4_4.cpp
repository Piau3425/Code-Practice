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
    vector<PII> v(n);
    for (auto &i : v) cin >> i.se >> i.fi;
    sort(all(v));
    int last, cnt; last = -1; cnt = 0;
    for (auto &i : v) if (i.se > last) last = i.fi, cnt++;
    cout << cnt;
}