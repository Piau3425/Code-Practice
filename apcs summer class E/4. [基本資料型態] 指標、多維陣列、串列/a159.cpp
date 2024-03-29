#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int siz;
vector<int> row, col;

int main(){
    while(1){
        cin >> siz;
        if(siz == 0)
            break;
        bool ary[siz][siz] = {false};
        for(int i = 0; i < siz; i++){
            for(int j = 0; j < siz; j++){
                cin >> ary[i][j];
            }
        }

        for(int i = 0; i < siz; i++){
            int val = 0;
            for(int j = 0; j < siz; j++){
                if(ary[i][j])
                    val++;
            }
            if(val%2 != 0){
                row.push_back(i);
            }
        }
        for(int i = 0; i < siz; i++){
            int val = 0;
            for(int j = 0; j < siz; j++){
                if(ary[j][i])
                    val++;
            }
            if(val%2 != 0){
                col.push_back(i);
            }
        }

        if(row.empty() && col.empty()){
            cout << "OK" << endl;
        }
        else if(row.size() == 1 && col.size() == 1){
            printf("Change bit (%d,%d)\n", row[0]+1, col[0]+1);
        }
        else{
            cout << "Corrupt" << endl;
        }

        row.clear(); col.clear();
    }
}
