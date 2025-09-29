#include <bits/stdc++.h>
using namespace std;

struct boss {
    int x, y, s, t;
    bool alive = true;
};

bool alive(vector<boss> &b) {
    for (auto &i : b) if (i.alive) return true;
    return false;
}

int n, m, k;

bool checkB(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<boss> b(k);
    for (auto &i : b) cin >> i.x >> i.y >> i.s >> i.t;
    
    while (alive(b)) {
        for (auto &i : b) if (i.alive) v[i.x][i.y]++;
        for (auto &i : b) {
            i.x += i.s;
            i.y += i.t;
            if (!checkB(i.x, i.y)) i.alive = false;
        }

        vector<pair<int, int>> ex;
        for (auto &i : b) {
            if (!i.alive) continue;
            if (v[i.x][i.y]) {
                i.alive = false;
                ex.emplace_back(i.x, i.y);
            }
        }
        
        for (auto i : ex) v[i.first][i.second] = 0;
    }
    
    int sum = 0;
    for (auto a : v) for (auto b : a) if (b) sum++;
    cout << sum; 
}