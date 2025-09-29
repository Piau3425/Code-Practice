#include <iostream>
#include <vector>
using namespace std;

int main(){
    int row, col, pen, x, y, color, time;
    cin >> row >> col >> pen;
    vector<vector<int>> plot(row, vector<int>(col, 0));

    for(int i = 0; i < pen; i++){
        cin >> y >> x >> time >> color;
        if(time == 0)
            plot[y][x] += color;
        else
            for(int r = 0; r < row; r++)
                for(int c = 0; c < col; c++)
                    if(abs(y - r) + abs(x - c) <= time)
                        plot[r][c] += color;
    }

    for(auto a : plot){
        for(auto b : a)
            cout << b << ' ';
        cout << '\n';
    }
}