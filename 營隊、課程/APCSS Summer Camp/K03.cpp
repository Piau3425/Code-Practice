#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 左上右下
vector<string> mp;
vector<vector<int>> vis;
int sum = 0;

bool outBorder(int y, int x, int row, int col){
    return x < 0 || x >= col || y < 0 || y >= row;
}

void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(outBorder(ny, nx, mp.size(), mp[0].size()) || mp[ny][nx] == '#' || vis[ny][nx]) continue;

        vis[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int main(){
    int n, m, col;
    cin >> n >> m;
    mp.resize(n);
    vis.resize(n, vector<int>(m));

    for(auto &i : mp)
        cin >> i;
    
    for(int y = 0; y < n; y++)
        for(int x = 0; x < m; x++)
            if(!vis[y][x] && mp[y][x] == '.'){
                dfs(y, x);
                sum++;
            }

    cout << sum;
}