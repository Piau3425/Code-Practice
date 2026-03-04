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

void solve() {
    
}

signed main() { WA();
    vector<int> v;int n; cin >> n;
    for (int x; cin >> x;) {
        if (x) v.pb(x);
    }
    sort(all(v));
    int sum = 0;
    for (int i = 1; i < v.size()-1; i++) sum += v[i];
    sum /= v.size()-2;
    cout << sum;
}