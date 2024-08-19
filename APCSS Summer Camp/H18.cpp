#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
    int row, col, step;
    cin >> row >> col >> step;
    vector<vector<char>> v(row, vector<char>(col));
    map<int, pair<int, int>> m{
        {0, {0, -1}},
        {1, {1, 0}},
        {2, {1, 1}},
        {3, {0, 1}},
        {4, {-1, 0}},
        {5, {-1, -1}}
    };
    set<char> s;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cin >> v[i][j];
    }
    
    int move, x = 0, y = row-1;
    for(int i = 0; i < step; i++){
        cin >> move;
        if(x+m[move].first >= 0 && x+m[move].first < col && y+m[move].second >= 0 && y+m[move].second < row){
            x += m[move].first;
            y += m[move].second;
        }
        cout << v[y][x];
        s.insert(v[y][x]);
    }

    cout << '\n' << s.size();
}