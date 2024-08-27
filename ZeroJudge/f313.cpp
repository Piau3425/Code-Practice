#include <bits/stdc++.h>
using namespace std;

int r, c, k, m, dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

bool check(int x, int y, vector<vector<int>>& v) {
    return (x >= 0 && x < r && y >= 0 && y < c && v[x][y] != -1);
}

int main() {
    cin >> r >> c >> k >> m;
    vector<vector<int>> v(r, vector<int>(c));
    for (auto &a : v) for (auto &b : a) cin >> b;

    while (m--) {
        vector<vector<int>> bv = v;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) 
                for (int o = 0; o < 4; o++) if (check(i+dx[o], j+dy[o], v)) {
                        v[i+dx[o]][j+dy[o]] += bv[i][j]/k;
                        v[i][j] -= bv[i][j]/k;
                }
    }

    int mn = 1e9, mx = -1e9;
    for (auto a : v) for (auto b : a) {
            if (b == -1) continue;
            mn = min(b, mn);
            mx = max(b, mx);
    }
    cout << mn << '\n' << mx;
}