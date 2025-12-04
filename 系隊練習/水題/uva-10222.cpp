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
    string s, ans = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    while (getline(cin, s)) {
        for (auto &c : s) if (!isblank(c)) cout << ans[(ans.find(tolower(c))-2)]; else cout << ' ';
        cout << '\n';
    }
}  