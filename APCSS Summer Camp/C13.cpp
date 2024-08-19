#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--; c--;
    vector<vector<char>> v(n, vector<char>(m, 'X'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        	if (i == r || j == c) v[i][j] = 'O';
        	if (sqrt((i-r)*(i-r) + (j-c)*(j-c)) <= 2) v[i][j] = 'O';
            if (sqrt((i-r)*(i-r) + (j-c)*(j-c)) <= 1) v[i][j] = 'X';
        }
    }
    v[r][c] = 'V';

    for (auto a : v) {
        for (auto b : a) cout << b;
        cout << '\n';
    }
}