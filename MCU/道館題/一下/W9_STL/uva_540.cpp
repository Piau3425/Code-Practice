#include <bits/stdc++.h>
using namespace std;

#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() { WA();
    int n, C = 1;
    while (cin >> n, n) { cout << "Scenario #" << C++ << '\n';
        map<int, int> mp;
        vector<queue<int>> team(n+1);
        queue<int> line;
        for (int i = 1; i <= n; i++) {
            int t; cin >> t;
            while (t--) {
                int k; cin >> k;
                mp[k] = i;
            }
        }

        string cmd;
        while (cin >> cmd, cmd != "STOP") {
            if (cmd == "ENQUEUE") {
                cin >> n;
                if (team[mp[n]].empty()) line.push(mp[n]);
                team[mp[n]].push(n);
            }
            else {
                cout << team[line.front()].front() << '\n';
                team[line.front()].pop();
                if (team[line.front()].empty()) line.pop();
            }
        }
        cout << '\n';
    }
}