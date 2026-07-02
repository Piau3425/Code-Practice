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
    for (int n, m, a, b; cin >> n >> m && (n || m);) {
        vector<vector<int>> v(n);
        vector<int> w(n, 0), ans;
        
        while (m--) {
            cin >> a >> b;
            v[--a].push_back(--b);
            w[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) if (!w[i]) q.push(i);
        
        while (q.size()) {
            cout << q.front()+1 << ' ';
            for (auto i : v[q.front()]) if (!(--w[i])) q.push(i);
            q.pop();
        }

        cout << '\n';
    }
}