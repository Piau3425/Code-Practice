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
    vector<int> v;
    v.pb(1);
    cout << v.capacity();
    v.pb(1); cout << v.capacity();
    v.clear();
    cout << '\n' << v.size() << ' ' << v.capacity();
}