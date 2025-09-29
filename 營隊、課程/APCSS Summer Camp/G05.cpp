#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 1, tmp;
    while (cin >> n) {
        cout << "Line #" << cnt << '\n';
        vector<int> v(10000000, -1); // idx = 人代號, val = 第幾團體
        vector<queue<int>> team(n);
        queue<int> line;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            while (t--) {
                cin >> tmp;
                v[tmp] = i;
            }
        }
        
        string cmd;
        while (cin >> cmd && cmd != "STOP") {
            if (cmd == "ENQUEUE") {
                cin >> tmp;
                if (v[tmp]+1) {
                    if (team[v[tmp]].empty()) line.push(v[tmp]);
                    team[v[tmp]].push(tmp);
                }
                else line.push(tmp+1000);
            }
            else {
                if (line.front() > 1000) {
                    cout << line.front()-1000 << '\n';
                    line.pop();
                }
                else {
                    cout << team[line.front()].front() << '\n';
                    team[line.front()].pop();
                    if (team[line.front()].empty()) line.pop();
                }
            }
        }

        cnt++;
    }
}