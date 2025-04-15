#include <bits/stdc++.h>
#include "function.h"
#define all(x) (x).begin(), (x).end()
using namespace std;

void dfs(int x, int y, vector<vector<char>>&v, int r, int c) {
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (ny >= 0 && ny < c && nx >= 0 && nx < r && !vis[nx][ny] && grid[nx][ny] == '*') {
            vis[nx][ny] = 1;
            v[nx][ny] = '*';
            dfs(nx, ny, v);
        }
    }
}

void adjust(int row, int col) {
    vis.assign(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!vis[i][j] && grid[i][j] == '*') {
                vector<vector<char>> omg(row, vector<char>(col, '.'));
                omg[i][j] = '*';
                vis[i][j] = 1;
                dfs(i, j, omg, row, col);
                bool moveable = true;
                for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) if (omg[i][j] == '*' && (i+1 == row || (i+1 < row && grid[i+1][j] == '#'))) moveable = false;
                for (int i = row-1; i >= 0; i--) for (int j = 0; j < col; j++) if (omg[i][j] == '*' && !moveable) grid[i][j] = '#';
            }
        }
    }
}

void Scene::update(int p) {
    while (gameTimer <= p) {
        vis.assign(row, vector<int>(col, 0));
        vector<vector<char>> tmp(row, vector<char>(col, '.'));
        for (int i = 0; i < row; i++) for(int j = 0; j < col; j++) if (grid[i][j] == '#') tmp[i][j] = '#';
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!vis[i][j] && grid[i][j] == '*') {
                    vector<vector<char>> omg(row, vector<char>(col, '.'));
                    omg[i][j] = '*';
                    vis[i][j] = 1;
                    dfs(i, j, omg, row, col);
                    bool moveable = true;
                    for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) if (omg[i][j] == '*' && (i+1 == row || (i+1 < row && grid[i+1][j] == '#'))) moveable = false;
                    for (int i = row-1; i >= 0; i--) for (int j = 0; j < col; j++) if (omg[i][j] == '*') tmp[i+moveable][j] = (moveable ? '*' : '#');
                }
            }
        }
        grid = move(tmp);
        for (int i = 0; i < row; i++) if (checkRow(i)) eliminate(i);
        gameTimer++;
    }
}

void Scene::addBlock(int x, int y, char **block) {
    x--, y--;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (block[i][j] == '*') grid[x+i][y+j] = '*';
}

bool Scene::checkRow(int r) const {
    for (int i = 0; i < col; i++) if (grid[r][i] != '#') return false;
    return true;
}

void Scene::eliminate(int r) {
    for (int i = r; i > 0; i--) for (int j = 0; j < col; j++) grid[i][j] = grid[i-1][j];
    fill(all(grid[0]), '.');
}

void Scene::print() {
    adjust(row, col);
    bool ck = 1;
    while (ck) {
        ck = 0;
        for (int i = 0; i < row; i++) if (checkRow(i)) eliminate(i), ck = 1;
    }
    adjust(row, col);
    
    for (auto &i : grid) {
        for (auto j : i) cout << j;
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    int n, m, t, k, p, x, y;
    cin >> n >> m >> t;
    Scene scene(n, m);
    cin >> k;
    
    char **block = (char**)malloc(sizeof(char*)*3);
    for(int i = 0; i < 3; i++) 
        block[i] = (char*)malloc(sizeof(char)*3);

    while (k--) {
        cin >> p >> x >> y;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++)
                cin >> block[i][j];
        }
        if(p > t) continue;
        scene.update(p);
        scene.addBlock(x, y, block);
    }
    scene.update(t);
    scene.print();

    return 0;
}