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
    int n; for (cin >> n; n--;) {
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                reverse(s.begin() + i+1, s.end());
            }
            else if (s[i] == 'b') {
                s += s.substr(i+1);
            }
            else if (s[i] == 'c') {
                s.erase(i+1, 2);
            }
        }
        cout << s << '\n';
    }
}