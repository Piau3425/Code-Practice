#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool check(int y, int x, vector<vector<int>>& v, int k){
    return x < k && x >= 0 && y < k && y >= 0 && !v[y][x];
}

int main(){
    int n;
    cin >> n;

    int val = 1, x = 0, y = 0;
    vector<vector<int>> v(n, vector<int> (n, 0));
    v[0][0] = 1;
    while(val < n*n){
        while(check(y, x+1, v, n))
            v[y][++x] = ++val;
        while(check(y+1, x, v, n))
            v[++y][x] = ++val;
        while(check(y, x-1, v, n))
            v[y][--x] = ++val;
        while(check(y-1, x, v, n))
            v[--y][x] = ++val;
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << v[i][j] << " \n"[j+1 == n];
}