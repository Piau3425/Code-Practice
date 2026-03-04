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

void solve() {
    string s; getline(cin, s);
    int a, b, neg = 1, after = 1; a = b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') neg = -1;
        else if (s[i] == '=') after = -1;
        else {
            if (isdigit(s[i])) {
                int now = s[i]-'0';
                while (isdigit(s[++i])) now = now*10+s[i]-'0';
                if (s[i] == 'x') b += now*neg*after;
                else a += now*neg*after, i--;
            }
            else if (s[i] == 'x') b += neg*after;
            neg = 1;
        }
    }
    b *= -1;
    
    if (!a && !b) return cout << "IDENTITY\n", void();
    if (!b) return cout << "IMPOSSIBLE\n", void();
    cout << floor((double)a/b) << '\n';
}

signed main() { WA();
    int t; for (cin >> t, cin.ignore(); t--;) solve();
}