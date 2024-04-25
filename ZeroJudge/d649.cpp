#include <iostream>
using namespace std;

int main(){
    int len;
    while(cin >> len && len != 0){
        int line = len-1;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < line; j++)
                cout << "_";
            for(int k = 0; k < len-line; k++)
                cout << "+";
            cout << "\n";
        line--;
        }
    }
}