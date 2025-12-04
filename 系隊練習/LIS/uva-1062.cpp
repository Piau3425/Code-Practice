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
    for (string s; cin >> s, s != "end";) {
        vector<int> len(s.size(), 1);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (s[i] > s[j]) len[i] = max(len[i], len[j]+1);
            }
        }
        cout << "Case " << ++T << ": " << *max_element(all(len)) << '\n';
    }
}