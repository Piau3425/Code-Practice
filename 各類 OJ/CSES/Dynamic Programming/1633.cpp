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
    vector<int> v(1000001);
    int p = 1e9+7;
    for (int i = 1; i <= 6; i++) v[i] = 1;
    int n; cin >> n;
    for (int i = 2; i <= n; i++) for (int j = i-6; j < i; j++)
    if (j > 0) v[i] = (v[i]+v[j])%p;
    cout << v[n] << '\n';
}