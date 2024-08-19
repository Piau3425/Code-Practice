#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> v, vis;
int n, m, sum = 0, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool checkB(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void f(int x, int y) {
    int mx, my, mn = 1000000;
    for (int i = 0; i < 4; i++) {
        if (checkB(x+dx[i], y+dy[i]) && vis[x+dx[i]][y+dy[i]] && v[x+dx[i]][y+dy[i]] < mn) {
            mx = dx[i];
            my = dy[i];
            mn = v[x+mx][y+my];
        }
    }
    
    if (mn == 1000000) return;
    vis[x+mx][y+my] = 0;
    sum += v[x+mx][y+my];
    /*
    for (auto a : vis) { for (auto b : a) cout << b << ' '; cout << '\n'; }
    cout << '\n';
    */
    f(x + mx, y + my);
}

signed main() {
    int sx, sy, mn = 1e9;
    cin >> n >> m;
    v.resize(n, vector<int>(m));
    vis.resize(n, vector<int>(m, 1));


    for (auto &a : v) for (auto &b : a) cin >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] < mn) {
                mn = v[i][j];
                sx = i; sy = j;
            }
        }
    }
    
    vis[sx][sy] = 0;
    sum += v[sx][sy];
    /*
    for (auto a : vis) { for (auto b : a) cout << b << ' '; cout << '\n'; }
    cout << '\n';
    */
    f(sx, sy);
    cout << sum;
}