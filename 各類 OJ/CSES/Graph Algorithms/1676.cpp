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

vector<int> anc, sz;
int mx = 1;

int Find(int x) {
    return x == anc[x] ? x : anc[x] = Find(anc[x]);
}

bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    if (a > b) swap(a, b);
    return anc[b] = a, sz[a] += sz[b], mx = max(mx, sz[a]), true;
}

signed main() { WA();
    int n, m; cin >> n >> m;
    anc.assign(n+1, 0);
    sz.assign(n+1, 1);
    iota(all(anc), 0);
    while (m--) {
        int a, b; cin >> a >> b;
        if (Union(a, b)) n--;
        cout << n << ' ' << mx << '\n';
    }
}