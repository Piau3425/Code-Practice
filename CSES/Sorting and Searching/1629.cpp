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
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &i : v) cin >> i.se >> i.fi;
    sort(all(v));

    int last = 0, cnt = 0;
    for (auto &i : v) if (last <= i.se) cnt++, last = i.fi;

    cout << cnt;
}