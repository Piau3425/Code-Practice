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
#define TIIIS tuple<int, int, int, string>

signed main() { WA();
    int t;
    for (cin >> t; t--;) {
        int a, b; cin >> a >> b;
        priority_queue<TIIIS, vector<TIIIS>, greater<TIIIS>> pq;
        for (int i = 0; i < a; i++) {
            string s; int k; cin >> s >> k;
            pq.emplace(k, i, k, s);
        }
        while (b--) {
            auto [k, i, p, s] = pq.top(); pq.pop();
            cout << k << ' ' << s << '\n';
            pq.emplace(k+p, i, p, s);
        }
    }
}