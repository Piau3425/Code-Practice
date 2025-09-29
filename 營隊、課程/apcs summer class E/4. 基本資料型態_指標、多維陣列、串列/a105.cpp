#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int row, col, row1, row2, col1, col2, treesum;
    cin >> col >> row;
    bool ary[row+1][col+1];
    memset(ary, false, sizeof(ary));

    cin >> treesum;
    for(int k = 0; k < treesum; k++){
        cin >> col1 >> row1 >> col2 >> row2;
        if(row1 == row2){
            if(col1 > col2){   // need col1 < col2
                swap(row1, row2);
                swap(col1, col2);
            }
            for(int i = 0; i < col2-col1+1; i++)
                ary[row1][col1+i] = true;
        }
        else if(col1 == col2){
            if(row1 > row2){
                swap(row1, row2);
                swap(col1, col2);
            }
            for(int i = 0; i < row2-row1+1; i++)
                ary[row1+i][col1] = true;
        }
        else{
            if(col1 > col2){   // need col1 < col2
                swap(row1, row2);
                swap(col1, col2);
            }
            if(row1 > row2){
                for(int i = 0; i < col2-col1+1; i++)
                    ary[row1-i][col1+i] = true;
            }
            else{
                for(int i = 0; i < col2-col1+1; i++)
                    ary[row1+i][col1+i] = true;
            }
        }
    }

    /*for(int i = 0; i < row+1; i++){
        for(int j = 0; j < col+1; j++){
            if(ary[i][j])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }*/
    int tree = 0;
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            if(ary[i][j])
                tree++;
        }
    }
    cout << tree;
}
