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

    while(n--){
        int k, r, val = 1, x = 0, y = 0;
        cin >> k >> r;
        vector<vector<int>> v(k, vector<int> (k, 0));
        v[0][0] = 1;
        if(r == 1){
            while(val < k*k){
                while(check(y, x+1, v, k))
                    v[y][++x] = ++val;
                while(check(y+1, x, v, k))
                    v[++y][x] = ++val;
                while(check(y, x-1, v, k))
                    v[y][--x] = ++val;
                while(check(y-1, x, v, k))
                    v[--y][x] = ++val;
            }
        }
        else {
            while(val < k*k){
                while(check(y+1, x, v, k))
                    v[++y][x] = ++val;
                while(check(y, x+1, v, k))
                    v[y][++x] = ++val;
                while(check(y-1, x, v, k))
                    v[--y][x] = ++val;
                while(check(y, x-1, v, k))
                    v[y][--x] = ++val;
            }
        }
        
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++)
                cout << setw(5) << v[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
}