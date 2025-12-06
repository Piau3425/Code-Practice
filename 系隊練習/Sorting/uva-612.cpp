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
    int t, n = 0; for (cin >> t; t--;) {
        if (n) cout << '\n';
        int id = 0; cin >> n >> n;
        vector<tuple<int, int, string>> v(n);
        for (auto &t : v) {
            cin >> get<2>(t); get<1>(t) = id++;
            for (int i = 0; i < get<2>(t).size(); i++)
            for (int j = i+1; j < get<2>(t).size(); j++)
            get<0>(t) += get<2>(t)[i] > get<2>(t)[j];
        }
        sort(all(v));
        for (auto &i : v) cout << get<2>(i) << '\n';
    }
}