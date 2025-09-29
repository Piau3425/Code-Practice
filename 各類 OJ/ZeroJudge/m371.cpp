#include <iostream>
#include <vector>
using namespace std;

int main(){
    int row, col, score = 0;
    bool flag = true;
    cin >> row >> col;
    vector<vector<int>> v(row, vector<int>(col));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> v[i][j];

    while(flag){
        flag = false;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col-1; j++){
                if(v[i][j] == -1)
                    continue;

                for(int k = j+1; k < col; k++){
                    if(v[i][j] == v[i][k]){
                        score += v[i][j];
                        v[i][j] = -1;
                        v[i][k] = -1;
                        flag = true;
                        break;
                    }
                    else if(v[i][k] != -1)
                        break;
                }
            }
        }

        for(int i = 0; i < col; i++){
            for(int j = 0; j < row-1; j++){
                if(v[j][i] == -1)
                    continue;

                for(int k = j+1; k < row; k++){
                    if(v[j][i] == v[k][i]){
                        score += v[j][i];
                        v[j][i] = -1;
                        v[k][i] = -1;
                        flag = true;
                        break;
                    }
                    else if(v[k][i] != -1)
                        break;
                }
            }
        }
    }

    cout << score;
}