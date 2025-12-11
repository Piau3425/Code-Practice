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
    int n; cin >> n;
    vector<tuple<int, int, int>> v(n);
    int id = 0;
    for (auto &[a, b, i] : v) cin >> a >> b, i = id++;
    sort(all(v));
    priority_queue<PII, vector<PII>, greater<>> pq;
    priority_queue<int, vector<int>, greater<>> room;
    id = 0;
    vector<int> ans(n);
    for (auto &[sta, ed, i] : v) {
        while (pq.size() && pq.top().fi < sta) {
            room.push(pq.top().se);
            pq.pop();
        }
        if (room.empty()) room.push(++id);
        ans[i] = room.top();
        pq.push({ed, room.top()}); room.pop();
    }
    cout << id << '\n';
    for (auto &i : ans) cout << i << ' ';
}