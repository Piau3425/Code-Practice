/*
左孩子右兄弟字典樹
*/

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
#define N 4000001

int ans, id;
vector<int> val(N), son(N), bro(N);
vector<char> chr(N);

void insert(string s) {
    int par = 0, n = s.size();
    for (int i = 0; i <= n; i++) {
        int cur = son[par];
        for (; cur; cur = bro[cur]) if (chr[cur] == s[i]) break;
        if (!cur) {
            cur = ++id;
            bro[cur] = son[par];
            son[par] = cur;
            chr[cur] = s[i];
            val[cur] = son[cur] = 0;
        }
        ans += (val[par]-val[cur]) * (i*2+1);
        if (s[i] == '\0') {
            ans += val[cur]*(i*2+2);
            val[cur]++;
        }
        val[par]++;
        par = cur;
    }
}

signed main() { WA();
    int T = 0;
    for (int t; cin >> t, t;) {
        son[0] = bro[0] = val[0] = ans = id = 0;
        string s;
        while (t--) {
            cin >> s;
            insert(s);
        }
        cout << "Case " << ++T << ": " << ans << '\n';
    }
}