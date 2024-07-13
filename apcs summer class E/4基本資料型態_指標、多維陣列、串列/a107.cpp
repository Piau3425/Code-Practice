#include <iostream>
#include <algorithm>
using namespace std;

char A[5][5] = {
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'j'},
    {'k', 'l', 'm', 'n', 'o'},
    {'p', 'r', 's', 't', 'u'},
    {'v', 'w', 'x', 'y', 'z'}
};

char B[5][5] = {
    {'E', 'X', 'A', 'M', 'P'},
    {'L', 'B', 'C', 'D', 'F'},
    {'G', 'H', 'I', 'J', 'K'},
    {'N', 'O', 'R', 'S', 'T'},
    {'U', 'V', 'W', 'Y', 'Z'}
};

int main(){
    int len, row1, row2, col1, col2;
    cin >> len;
    cin.ignore();
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());

    if(islower(s[0])){
        for(int k = 0; k < len; k += 2){
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    if(s[k] == A[i][j]){
                        row1 = i;
                        col1 = j;
                        //cout << s[k] << " == " << A[i][j] << " " << i << " " << j << endl;
                    }
                    if(s[k+1] == A[i][j]){
                        row2 = i;
                        col2 = j;
                        //cout << s[k+1] << " == " << A[i][j] << " " << i << " " << j << endl;
                    }
                }
            }
            cout << B[row1][col2] << B[row2][col1];
        }
    }
    else{
        for(int k = 0; k < len; k += 2){
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    if(s[k] == B[i][j]){
                        row1 = i;
                        col1 = j;
                    }
                    if(s[k+1] == B[i][j]){
                        row2 = i;
                        col2 = j;
                    }
                }
            }
            cout << A[row1][col2] << A[row2][col1];
        }
    }
}
