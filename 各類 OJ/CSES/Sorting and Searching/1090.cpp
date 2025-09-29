#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n, m, l, h, cnt = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(all(v));
    l = 0, h = n-1;
    while (l <= h) {
        if (v[l] + v[h] <= m) l++, h--, cnt++;
        else h--, cnt++;
    }
    cout << cnt;
}