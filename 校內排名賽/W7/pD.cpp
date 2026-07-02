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

signed v[10000005][2], cnt[10000005];

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int mxlen = 0, id = 0;
        v[0][0] = v[0][1] = 0;
        cnt[0] = 0;
        int n; for (cin >> n; n--;) {
            string s; cin >> s;
            int now = 0;
            for (int i = 0; i < s.size(); i++) {
                int bit = s[i]-'0';
                if (!v[now][bit]) {
                    v[now][bit] = ++id;
                    v[id][0] = v[id][1] = 0;
                    cnt[id] = 0;
                }
                now = v[now][bit];
                cnt[now]++;
                mxlen = max(mxlen, cnt[now]*(i+1));
            }
        }
        cout << mxlen << '\n';
    }
}