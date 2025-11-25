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
#define TIS tuple<int, int, int, int, string>

signed main() { WA();
    int n, t, p, d, c; string id;
    priority_queue<TIS, vector<TIS>, greater<TIS>> v, pq;
    for (cin >> n; n--;) {
        cin >> id >> t >> c >> d >> p;
        v.push({t, p, d, c, id});
    }
    int now = 0;
    vector<string> ans;
    while (v.size() || pq.size()) {
        while (v.size() && get<0>(v.top()) <= now) {
            tie(t, p, d, c, id) = v.top(); v.pop();
            pq.push({p, d, c, t, id});
        }
        if (pq.size()) {
            tie(p, d, c, t, id) = pq.top(); pq.pop();
            ans.pb(id);
            now += c;
        }
        else now = get<0>(v.top());
    }
    for (auto &i : ans) cout << i << " \n"[&i == &ans.back()];
}