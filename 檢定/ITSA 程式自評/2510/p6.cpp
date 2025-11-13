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
            char c = s[i];
            if (c == 'a') reverse(s.begin()+i+1, s.end());
            else if (c == 'b') s += s.substr(i+1);
            else if (c == 'c') {   
                if (s.size() > i+1) s.erase(s.begin()+i+1);
                if (s.size() > i+1) s.erase(s.begin()+i+1);
            }
        }
        cout << s << '\n';
    }
}