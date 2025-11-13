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

vector<int> anc;

int Find(int x) {
    return x == anc[x] ? x : anc[x] = Find(anc[x]);
}

bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    if (a > b) swap(a, b);
    return anc[b] = a, true;
}

signed main() { WA();
    int n, t = 0; while (cin >> n) { if (t++) cout << '\n';
        int sum = 0;
        anc.assign(n, 0); n--;
        vector<tuple<int, int, int>> v;
        while (n--) {
            int a, b, w; cin >> a >> b >> w;
            a--, b--, sum += w;
            v.pb({w, a, b});
        }
        int k, mn = 1e9;
        for (cin >> k; k--;) {
            int a, b, w; cin >> a >> b >> w;
            a--, b--;
            v.pb({w, a, b});
        }
        for (cin >> k; k--;) {
            int a, b, w; cin >> a >> b >> w;
            a--, b--;
            v.pb({w, a, b});
        }
        sort(all(v));
        iota(all(anc), 0);
        {
            int sum = 0;
            for (auto &[w, a, b] : v) if (Union(a, b)) sum += w;
            mn = min(sum, mn);
        }

        cout << sum << '\n' << mn << '\n';
    }
}