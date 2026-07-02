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
    int t = 1, T; for (cin >> T; t <= T; t++) { cout << "Case " << dec << t << ":";
        string s; cin >> s;
        vector<unsigned char> v(100); int idx = 0;
        for (auto &c : s) {
            if (c == '>') idx = (idx+1)%100;
            else if (c == '<') idx = (idx+99)%100;
            else if (c == '+') v[idx] = (v[idx]+1)%256;
            else if (c == '-') v[idx] = (v[idx]+255)%256;
        }
        for (auto &i : v) cout << ' ' << uppercase << hex << (i>>4) << (i&0x0f);
        cout << '\n';
    }
}