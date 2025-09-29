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
    int n, k; cin >> n >> k;
    vector<tuple<int, int, int>> v(n);
    for (auto &i : v) {
        cin >> get<0>(i) >> get<1>(i);
        get<2>(i) = &i-v.data();
    }
    sort(all(v), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        int a1, a2, a3, b1, b2, b3;
        tie(a1, a2, a3) = a;
        tie(b1, b2, b3) = b;
        return a1 > b1;
    });
    v.erase(v.begin()+k, v.end());
    sort(all(v), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        int a1, a2, a3, b1, b2, b3;
        tie(a1, a2, a3) = a;
        tie(b1, b2, b3) = b;
        return a2 > b2;
    });
    cout << get<2>(v.front())+1;
}