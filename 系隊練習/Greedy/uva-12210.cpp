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
    int T = 0;
    for (int b, s; cin >> b >> s, b+s;) { cout << "Case " << ++T << ": ";
        vector<int> vb(b), vs(s);
        for (auto &i : vb) cin >> i;
        for (auto &i : vs) cin >> i;
        if (b <= s) cout << "0\n";
        else cout << b-s << ' ' << *min_element(all(vb)) << '\n';
    }
}