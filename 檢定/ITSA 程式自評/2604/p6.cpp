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
#define Task tuple<int, int, int, int, string>

signed main() { WA();
    int n; cin >> n;
    vector<Task> v;
    for (int i = 0; i < n; i++) {
        string id; int t, c, d, p;
        cin >> id >> t >> c >> d >> p;
        v.emplace_back(p, d, t, c, id);
    }

    sort(all(v), [](Task& a, Task& b) {
        return get<2>(a) < get<2>(b);
    });
    
    priority_queue<Task, vector<Task>, greater<Task>> pq;
    vector<string> ans;
    int now = 0, idx = 0;

    while (ans.size() < n) {
        while (idx < n && get<2>(v[idx]) <= now) {
            pq.push(v[idx]);
            idx++;
        }
        if (pq.empty()) {
            now = get<2>(v[idx]);
            continue;
        }

        Task best = pq.top(); pq.pop();
        ans.pb(get<4>(best));
        now += get<3>(best);
    }
    
    for (auto &s : ans) cout << s << " \n"[&s == &ans.back()];
}