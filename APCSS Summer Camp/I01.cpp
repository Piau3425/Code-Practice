#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> v(8, -999); // v[y] = x;
vector<vector<char>> mask(8, vector<char>(8));

void print(vector<int> &v) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) cout << (v[i] == j ? "+" : "-") << ' ';
        cout << '\n';
    }
}

bool check(vector<int> &v, int y, int x) {
    for (int i = 0; i < 8; i++)
        if (v[i] == x || v[i] - i == x - y || v[i] + i == x + y || mask[y][x] == '*') return false;
    return true;
}

void queen(vector<int> v, int y) {
    if (y > 7) {
        //print(v);
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++) if (check(v, y, i)) {
        v[y] = i;
        queen(v, y+1);
    }
}

int main() {
    for (auto &i : mask) for (auto &j : i) cin >> j;
    queen(v, 0);
    cout << ans;
}