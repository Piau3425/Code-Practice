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

void msort(auto v, int n) {
    if (n > 1) {
        int h = n/2, i = 0, j = h, k = 0;
        msort(v, h);
        msort(v+h, n-h);
        vector<int> t(n);
        while (k < n) t[k++] = j == n || i < h && v[i] < v[j] ? v[i++] : v[j++];
        while (k--) v[k] = t[k];
    }
}

signed main() { WA();
    vector<int> v;
    for (int n; cin >> n; v.pb(n));
    msort(v.begin(), (int)v.size());
    for (auto &i : v) cout << i << ' ';
}