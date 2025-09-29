#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
#0 WA line:10
My output: 6 8
Correct Answer: 4 4
*/

queue<pair<int, int>> q;
vector<vector<int>> map, vis;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, -1, -1, -1, 0, 1, 1, 1,}; // 左, 左上, 上, 右上, 右, 右下, 下, 左下
int row, col, x, y, tailX, tailY;

bool outBorder(int y, int x){
    return y >= row || y < 0 || x >= col || x < 0;
}

int main(){
    while(1){
        cin >> row >> col;
        if(!row && !col)
            break;
        
        map.clear();
        vis.clear();
        map.resize(row, vector<int>(col));
        vis.resize(row, vector<int>(col, 0));

        for(auto &a : map)
            for(auto &b : a)
                cin >> b;

        cin >> y >> x;
        vis[y][x] = 1;
        tailX = x; tailY = y;
        q.push({y, x});

        while(q.size()){
            auto [y, x] = q.front();
            q.pop();
            for(int i = 0; i < 8; i++){
                int ny = y + dy[i], nx = x + dx[i];
                if(outBorder(ny, nx) || vis[ny][nx]) continue;

                vis[ny][nx] = 1;
                if(map[ny][nx]){
                    tailX = nx; tailY = ny;
                    while(q.size()) q.pop();
                    q.push({ny, nx});
                    break;
                }
                q.push({ny, nx});
            }
        }

        cout << tailY << ' ' << tailX << '\n';
    }
}