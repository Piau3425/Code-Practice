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

vector<PII> xy = {
    {0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8},
    {0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}
};

signed main() { WA();
    string s; int n;
    while (cin >> n) s += char(n+'0');
    queue<pair<string, int>> q;
    unordered_map<string, int> vis;
    vis[s] = 1; q.push({s, 0});
    int ans = -1;
    while (q.size()) {
        auto [s, step] = q.front(); q.pop();
        if (s == "123456789") {
            ans = step;
            break;
        }
        for (auto &[x, y] : xy) {
            swap(s[x], s[y]);
            if (vis.find(s) == vis.end()) vis[s] = 1, q.push({s, step+1});
            swap(s[x], s[y]);
        }
    }
    cout << ans;
}