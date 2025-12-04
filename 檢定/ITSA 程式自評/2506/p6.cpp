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
    return (anc[x] == x ? x : anc[x] = Find(anc[x]));
}

bool Union(int a, int b) {
    int fa = Find(a), fb = Find(b);
    if (fa == fb) return false;
    anc[fb] = fa;
    return true;
}

signed main() {
    int n, m; cin >> n >> m;
    vector<string> vs(n); for (auto &i : vs) cin >> i;
    anc.assign(n, 0); iota(all(anc), 0);
    vector<tuple<int, int, int>> k;
    while (m--) {
        string a, b; int w;
        cin >> a >> b >> w;
        k.pb({w, find(all(vs), a) - vs.begin(), find(all(vs), b) - vs.begin()});
    }
    sort(all(k));

    int sum = 0;
    vector<PII> ans;
    for (auto &i : k) {
        int a, b, c;
        tie(a, b, c) = i;
        if (Union(b, c)) {
            ans.pb({b, c});
            sum += a;
        }
    }
    sort(all(ans));
    for (auto &i : ans) cout << '(' << vs[i.fi] << ' ' << vs[i.se] << ')';
    cout << '\n' << sum << '\n';
}