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

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    anc[b] = a;
}

signed main() { WA();
    int T; for (cin >> T; T--;) {
        int n; cin >> n; cin.ignore();
        anc.assign(n+1, 0);
        iota(all(anc), 0);
        string s;
        int t, f; t = f = 0;
        while (getline(cin, s), s.size()) {
            stringstream ss(s);
            char c; ss >> c;
            int a, b; ss >> a; ss >> b;
            if (c == 'c') Union(a, b);
            else if (Find(a) == Find(b)) t++;
            else f++;
        }
        cout << t << ',' << f << '\n';
        if (T) cout << '\n';
    }
}