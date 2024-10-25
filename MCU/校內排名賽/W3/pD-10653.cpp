#include <bits/stdc++.h>
using namespace std;

int sum, sx, sy, ex, ey;

int bfs(int y, int x) {
    if (y == sy && x == sx) return 1;

}

int main() {
    int r, c;
    while (cin >> r >> c, r+c) {
        vector<vector<int>> v(r, vector<int>(c, 0));
        int n, m, x, y;
        for (cin >> n; n; n--) for (cin >> y >> m; m; m--) {
            cin >> x;
            v[y][x] = 1;
        }

        
        cin >> sy >> sx >> ey >> ex;
        //for (auto &i : v) for (auto &j : i) cout << j << " \n"[&j == &i.back()];

        queue<pair<int, int>> q;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
        q.push({sy, sx});
        while (q.size()) {
            y = q.front().first; x = q.front().second;
            for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
                int nx = x+dx[i], ny = y+dy[j];
                if (nx >= c || nx < 0 || ny >= r || ny < 0 || v[ny][nx]) continue;
                else {
                    if ()
                }
            }
        }
    }
}