#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, dx[] = {-1, 0, 1, 0}, dy[]= {0, -1, 0, 1}; // 往左、上、右、下
vector<vector<char>> v; // 地圖
vector<vector<int>> vis; // 走訪紀錄

bool check(int y, int x) { // 判斷邊界與是否為坑洞
    return y >= 0 && y < n && x >= 0 && x < n && v[y][x] == '0';
}

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i]; // 四周的點座標
        if (check(ny, nx) && !vis[ny][nx]) {
            vis[ny][nx] = 1; // 標示已走過
            dfs(ny, nx);
        }
    }
}

signed main() {
    int cnt = 0;
    cin >> n;
    v.resize(n, vector<char>(n));
    vis.resize(n, vector<int>(n, 0));
    
    for (auto &i : v) for (auto &j : i) cin >> j; // 輸入地圖

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) { // 從 0, 0 開始遍歷
        if (v[i][j] == '0' && !vis[i][j]) { // 如果是未走訪的坑洞就進行 dfs
            dfs(i, j);
            cnt++; // 計數器
        }
    }
    cout << cnt; // 輸出答案
}