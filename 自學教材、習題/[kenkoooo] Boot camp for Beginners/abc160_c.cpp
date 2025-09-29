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
    int k, n; cin >> k >> n;
    int last = 0, mx = -1e9;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    for (int i = 0; i+1 < n; i++) mx = max(mx, v[i+1]-v[i]);
    mx = max(mx, k-v.back()+v.front());
    cout << k-mx;
}