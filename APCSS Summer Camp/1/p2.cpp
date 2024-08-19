#include <bits/stdc++.h>
using namespace std;

int n;

bool checkB(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int q1 = 0, q2 = -1e9, q3 = -1e9, q5 = 0, q6 = -1e9, q7 = -1e9;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int i = 0; i < n; i++) {
        int row = 0, col = 0;
        for (int j = 0; j < n; j++) {
            if (i == j || i+j == n-1) q1 += v[i][j];
            row += v[i][j];
            col += v[j][i];
        }
        q2 = max(q2, row);
        q3 = max(q3, col);
    }
    
    q2 = max(q2, 0);
    q3 = max(q3, 0);
    cout << q1 << ' ' << q2 << ' ' << q3 << '\n';

    vector<vector<int>> bv = v;
    int r, x1[] = {0, 0, -1, 1}, y1[] = {1, -1, 0, 0}, x2[] = {-1, -1, 1, 1}, y2[] = {1, -1, 1, -1};
    cin >> r;
    while (r--) {
        int x, y, t, c;
        cin >> x >> y >> t >> c;
        x--; y--;
        for (int i = 0; i < 4; i++) {
            if ((t == 1 || t == 3) && checkB(x+x1[i], y+y1[i])) {
                v[x+x1[i]][y+y1[i]] += c;
                v[x][y] -= c;
            }
            if ((t == 2 || t == 3) && checkB(x+x2[i], y+y2[i])) {
                    v[x+x2[i]][y+y2[i]] += c;
                    v[x][y] -= c;
            }
        }
    }

    for (auto i : v) {
        for (int j = 0; j < n; j++)
            cout << (j ? " " : "") << i[j];
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        int row = 0, col = 0;
        for (int j = 0; j < n; j++) {
            if (i == j || i+j == n-1) q5 += v[i][j];
            row += v[i][j];
            col += v[j][i];
        }
        q6 = max(q6, row);
        q7 = max(q7, col);
    }
    q6 = max(q6, 0);
    q7 = max(q7, 0);
    cout << q5 << ' ' << q6 << ' ' << q7 << '\n';
}