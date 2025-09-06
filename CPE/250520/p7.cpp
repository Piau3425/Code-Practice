#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

vector<int> anc;

int Find(int x) {
    return (anc[x] == x ? x : anc[x] = Find(anc[x]));
}

bool Union(int a, int b) {
    int fa = Find(a), fb = Find(b);
    if (fa == fb) return true;
    return anc[fb] = fa, false;
}

signed main() { WA();
    int t; while (cin >> t, t) {
        while (t--) {
            int n, m; cin >> n >> m;
            vector<tuple<int, int, int>> v;
            anc.resize(n+1);
            iota(all(anc), 0);
            // 我很想用 structured binding，但考慮到 CPE 是用 C++ 14 的版本問題，所以還是土法煉鋼好了
            while (m--) {
                int a, b, w;
                cin >> a >> b >> w;
                v.pb({w, a, b});
            }
            sort(all(v), greater<tuple<int, int, int>>());

            int ans = 0;
            for (auto &i : v) {
                int a, b, w;
                tie(w, a, b) = i;
                if (Union(a, b)) ans += w;
            }
            cout << ans << '\n';
        }
    }
}