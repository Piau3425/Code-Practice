#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, dx[] = {-1, 0, 1, 0}, dy[]= {0, -1, 0, 1};
vector<vector<char>> v;
vector<vector<int>> vis;

bool check(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n && v[y][x] == '0';
}

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (check(ny, nx) && !vis[ny][nx]) {
            vis[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
}

signed main() {
    int cnt = 0;
    cin >> n;
    v.resize(n, vector<char>(n));
    vis.resize(n, vector<int>(n, 0));
    
    for (auto &i : v) for (auto &j : i) cin >> j;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (v[i][j] == '0' && !vis[i][j]) {
            dfs(i, j);
            cnt++;
        }
    }
    cout << cnt;
}