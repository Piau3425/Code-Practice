#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cmp{
    bool operator()(pair<char, int> a, pair<char, int> b){
        if(a.second == b.second)
            return a.first < b.first;
        else
            return a.second > b.second;
    }
};

int lang[26] = {0};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 左上右下
vector<string> map;
vector<vector<int>> vis;
vector<pair<char, int>> result;

bool outBorder(int y, int x, int row, int col){
    return x < 0 || x >= col || y < 0 || y >= row;
}

void dfs(int y, int x, char lang){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(outBorder(ny, nx, map.size(), map[0].size()) || map[ny][nx] != lang|| vis[ny][nx]) continue;
        if(vis[ny][nx]) continue;

        vis[ny][nx] = 1;
        dfs(ny, nx, lang);
    }
}

int main(){
    int loop, row, col;
    cin >> loop;
    for(int k = 1; k <= loop; k++){
        map.clear();
        vis.clear();
        result.clear();
        fill(lang, lang + 26, 0);

        cin >> row >> col;
        map.resize(row);
        vis.resize(row, vector<int>(col));

        for(int i = 0; i < row; i++)
            cin >> map[i];
        
        for(int y = 0; y < row; y++){
            for(int x = 0; x < col; x++){
                if(!vis[y][x]){
                    lang[map[y][x] - 'a']++;
                    dfs(y, x, map[y][x]);
                }
            }
        }

        for(int i = 0; i < 26; i++)
            if(lang[i])
                result.push_back({i + 'a', lang[i]});
        sort(result.begin(), result.end(), Cmp());

        cout << "World #" << k << '\n';
        for(int i = 0; i < result.size(); i++)
            cout << result[i].first << ": " << result[i].second << '\n';
    }
}