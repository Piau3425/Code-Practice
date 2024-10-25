#include <bits/stdc++.h>
using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    while (cin >> n >> m && (n || m)) {
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