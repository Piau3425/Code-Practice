#include <bits/stdc++.h>
using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> v(n);
    vector<int> w(n, 0), ans;
    while (cin >> a >> b) {
        a--, b--;
        v[a].push_back(b);
        w[b]++;
    }

    queue<int> q;
    for (int i = 0; i < w.size(); i++) if (!w[i]) q.push(i);

    while (q.size()) {
        ans.push_back(q.front());
        for (auto i : v[q.front()]) {
            if (!(--w[i])) q.push(i);
        }
        q.pop();
    }

    if (ans.size() == n) {
        cout << "YES\n";
        for (auto i : ans) cout << i+1 << '\n';
    }
    else cout << "NO\n";
}