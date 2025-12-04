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
    int n; cin >> n;
    for (int T = 1; T <= n; T++) { cout << "Case " << T << ": ";
        int amount, tar; cin >> amount >> tar;
        vector<int> b, s;
        for (int i = amount; i; i--) {
            string str; cin >> str;
            if (str[0] == 'B') b.pb(stoi(str.substr(2)));
            else s.pb(stoi(str.substr(2)));
        }
        int ans = -1, fa = 0, fb = 0;
        for (int i = 0, j = 0; i < b.size() || j < s.size();) {
            if (j < s.size() && i < b.size() && s[j] <= b[i] || !(i < b.size())) {
                ans = max(s[j]-min(fa, fb), ans);
                if (fa < fb) fa = s[j];
                else fb = s[j];
                j++;
            }
            else {
                ans = max({b[i]-fa, b[i]-fb, ans});
                fa = fb = b[i];
                i++;
            }
        }
        cout << max({tar-fa, tar-fb, ans}) << '\n';
    }
}