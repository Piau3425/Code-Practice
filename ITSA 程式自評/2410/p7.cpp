#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, dx[] = {-1, 0, 1, 0}, dy[]= {0, -1, 0, 1};
vector<vector<char>> v;
vector<vector<int>> vst;

bool check(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        if (check(y+dy[i], x+dx[i]) && v[y+dy[i]][x+dx[i]] == '0' && vst[y+dy[i]][x+dx[i]]) {
            vst[y+dy[i]][x+dx[i]] = 0;
            dfs(y+dy[i], x+dx[i]);
        }
    }
}

signed main() {
    int cnt = 0;
    cin >> n;
    v.resize(n, vector<char>(n));
    vst.resize(n, vector<int>(n, 1));
    
    for (auto &i : v) for (auto &j : i) cin >> j;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '0' && vst[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}