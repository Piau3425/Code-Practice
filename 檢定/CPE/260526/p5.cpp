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
    int t = 0;
    for (string s; cin >> s, s != "end";) { cout << "Case " << ++t << ": ";
        vector<vector<char>> v;
        for (auto &c : s) {
            auto it = lower_bound(all(v), c, [](vector<char> a, char c){
                return c > a.back();
            });
            if (it == v.end()) v.pb(vector<char>(1, {c}));
            else it->pb(c);
        }
        cout << v.size() << '\n';
    }
}