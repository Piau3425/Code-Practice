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
    for (int a, b; cin >> a >> b, a+b;) {
        string s, ans; map<int, int> mp;
        int k = a%b, pos = 0, find = 0;
        cout << a/b << '.';
        while (k) {
            if (mp.count(k)) {
                cout << s.substr(0, mp[k]) << (ans = s.substr(mp[k]));
                find = 1;
                break;
            }
            s += to_string(k/b);
            mp[k] = s.size();
            k *= 10;
            
            k %= b;
        }
        if (!find) cout << s;
        cout << '\n' << ans.size() << '\n';
    }
}