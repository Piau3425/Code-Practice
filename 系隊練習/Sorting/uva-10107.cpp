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
    int n;
    vector<int> v;
    while (cin >> n) v.insert(lower_bound(all(v), n), n), cout << (v.size()&1 ? v[v.size()/2] : (v[v.size()/2] + v[v.size()/2-1])/2) << '\n';
}