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
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i; sort(all(v));
    int k, sum = 0;
    if (n&1) k = v[n/2];
    else k = v[n/2-1];
    for (auto &i : v) sum += abs(i-k);
    cout << sum << '\n';
}