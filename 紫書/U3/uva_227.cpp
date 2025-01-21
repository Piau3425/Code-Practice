#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

bool check(int y, int x) {
    return y < 0 || x < 0 || y >= 5 || x >= 5;
}

signed main() {
    string s; int t = 0;
    while (1) {
        vector<vector<char>> g(5);
        for (int i = 0; i < 5; i++) {
            getline(cin, s);
            if (s == "Z") exit(0);
            for (auto &c : s) g[i].pb(c);
        }

        int x, y;
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (g[i][j] == ' ') y = i, x = j;

        string dir = "ABRL"; char c;
        int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0 ,0}, ck = 0;;
        while (getline(cin, s)) {
            int leave = 0;
            if (s.back() == '0') leave = 1, s.pop_back();
            for (auto &c : s) {
                int nx = x + dx[dir.find(c)], ny = y + dy[dir.find(c)];
                if (check(ny, nx)) {
                    ck = 1;
                    break;
                }
                g[y][x] = g[ny][nx], g[ny][nx] = ' ', y = ny, x = nx;
            }
            if (leave) break;
        }
        if (t++) cout << '\n';
        cout << "Puzzle #" << t << ":\n";
        if (ck) cout << "This puzzle has no final configuration.\n";
        else for (auto &i : g) for (auto &j : i) cout << j << " \n"[&j == &i.back()];
    }
}