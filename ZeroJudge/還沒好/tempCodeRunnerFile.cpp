#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int row, col, step;
    cin >> row >> col >> step;
    vector<vector<char>> v(row, vector<char>(col));
    set<char> s;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cin >> v[i][j];
    }

    int move, x = 0, y = row-1;
    for(int i = 0; i < step; i++){
        cin >> move;
        x += (x+1 <= col-1 && (move == 1 || move == 2)) - (x-1 >= 0 && (move == 4 || move == 5));
        y += (y+1 <= row-1 && (move == 2 || move == 3)) - (y-1 >= 0 && (move == 0 || move == 5));
        cout << v[y][x];
        s.insert(v[y][x]);
    }

    cout << '\n' << s.size();
}