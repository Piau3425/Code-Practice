#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n; cin >> n;
    map<char, double> mp = {
        {'C', 12.01},
        {'H', 1.008},
        {'O', 16.00},
        {'N', 14.01}
    };
    
    while (n--) {
        string s; cin >> s;
        double sum = 0, ans = 0;
        char last = ' ';
        for (auto &c : s) {
            if (isalpha(c)) {
                if (last != ' ') ans += mp[last]*max(1.0, sum), sum = 0;
                last = c;
            }
            else sum = sum*10 + c-'0';
        }
        if (last != ' ') ans += mp[last]*max(1.0, sum);
        cout << fixed << setprecision(3) << ans << '\n';
    }
}