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

vector<int> anc, pa, sz, sum;

int Find(int x) {
    return anc[x] == x ? x : anc[x] = Find(anc[x]);
}

signed main() { WA();
    int n, m; while (cin >> n >> m) {
        anc.assign(n, 0); iota(all(anc), 0); pa = anc;
        sz.assign(n, 1);
        sum.assign(n, 0); iota(all(sum), 1);
        while (m--) {
            int cmd, p, q; cin >> cmd;
            if (cmd == 1) {
                cin >> p >> q; p--, q--;
                p = Find(pa[p]), q = Find(pa[q]);
                if (p != q) {
                    anc[p] = q;
                    sz[q] += sz[p];
                    sum[q] += sum[p];
                }
            }
            else if (cmd == 2) {
                cin >> p >> q; p--, q--;
                int u = Find(pa[p]), v = Find(pa[q]);
                if (u != v) {
                    pa[p] = v;
                    sz[u]--, sz[v]++;
                    sum[u] -= p+1, sum[v] += p+1;
                }
            }
            else {
                cin >> p; p--; p = Find(pa[p]);
                cout << sz[p] << ' ' << sum[p] << '\n';
            }
        }
    }
}