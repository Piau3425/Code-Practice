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
    int m, n, cnt = 0; cin >> m >> n;
    map<int, int> mp;
    m = (1 << m) - 1;
    while (n--) {
        string s; cin >> s;
        int now = 0;
        for (auto &c : s) now |= (1 << (c-'A'));
        cnt += mp[now^m];
        mp[now]++;
    }
    cout << cnt << '\n';
}