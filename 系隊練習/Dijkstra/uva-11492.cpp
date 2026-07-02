#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define TIII tuple<int, int, int>
#define PIS pair<int, string>

map<string, int> stoidx;
int id;

int f(string s) {
    if (stoidx.count(s)) return stoidx[s];
    return stoidx[s] = id++;
}

signed main() { WA();
    for (int n; cin >> n, n;) {
        string s, e; int si, ei;
        stoidx.clear(); id = 0;
        cin >> s >> e; si = f(s), ei = f(e);
        vector<vector<int>> w(n*2+5, vector<int>(27, INF));
        vector<vector<pair<int, string>>> v(n*2+5);
        while (n--) {
            string a, b, c; cin >> a >> b >> c;
            int ai = f(a), bi = f(b);
            v[ai].pb({bi, c});
            v[bi].pb({ai, c});
        }
        priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
        pq.push({0, si, 26}); w[si][26] = 0;
        while (pq.size()) {
            auto [nD, nS, nC] = pq.top(); pq.pop();
            if (nD > w[nS][nC]) continue;
            for (auto &[toS, toD] : v[nS]) {
                int toC = toD.front() - 'a';
                if (toC != nC && nD + toD.size() < w[toS][toC]) {
                    w[toS][toC] = nD + toD.size();
                    pq.push({w[toS][toC], toS, toC});
                }
            }
        }
        if (int mn = *min_element(all(w[ei])); mn == INF) cout << "impossivel\n";
        else cout << mn << '\n';
    }
}