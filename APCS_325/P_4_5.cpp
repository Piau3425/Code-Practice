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
    for (auto &i : v) cin >> i.fi;
    for (auto &i : v) cin >> i.se;
    sort(all(v), [](PII a, PII b){
        return (double)a.fi/a.se < (double)b.fi/b.se;
    });
    int sum = 0;
    for (int i = 0, now = 0; i < n; i++) {
        now += v[i].fi;
        sum += now*v[i].se;
    }
    cout << sum;
}