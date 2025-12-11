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
#define TIII tuple<int, int, int>

signed main() { WA();
    string s;
    priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
    while (getline(cin, s), s != "#") {
        stringstream ss(s); int id, w;
        ss >> s; ss >> id; ss >> w;
        pq.push({w, id, w});
    }
    int k; for (cin >> k; k--;) {
        auto [t, id, w] = pq.top(); pq.pop();
        cout << id << '\n';
        pq.push({t+w, id, w});
    }
}