#include <iostream>
#include <iomanip>
using namespace std;

bool checkH(int num[][4]);
bool checkV(int num[][4]);
bool checkD(int num[][4]);
bool isLine(int ary[][4]);

int main(){
    int total;
    scanf("N %d", &total);
    int bingo[total][4][4], choose[16];
    char name[total];

    for(int k = 0; k < total; k++){
        cin >> name[k];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> bingo[k][i][j];
            }
        }
    }

    char tmp;
    cin >> tmp;
    for(int i = 0; i < 16; i++)
        cin >> choose[i];

    int isbin = 0;
    for(int i = 0; i < 16 && isbin != 1; i++){
        //cout << "======N e x t======" << choose[i] << endl;
        cout << choose[i] << " ";
        for(int j = 0; j < total; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    if(bingo[j][k][l] == choose[i]){
                        bingo[j][k][l] = 0;
                    }
                }
            }
        }

        /*for(int j = 0; j < total; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    cout << setw(2) << bingo[j][k][l] << " ";
                }
                cout << endl;
            }
            cout << "============" << endl;
        }*/

        for(int j = 0; j < total; j++){
            if(isLine(bingo[j])){
                cout << name[j] << " ";
                isbin = 1;
            }
        }
    }
}




bool checkH(int num[][4]){
    for(int i = 0; i < 4; i++){
        int val = 0;
        for(int j = 0; j < 4; j++){
            if(num[i][j] == 0)
                val++;
        }
        if(val == 4)
            return true;
    }

    return false;
}

bool checkV(int num[][4]){
    for(int i = 0; i < 4; i++){
        int val = 0;
        for(int j = 0; j < 4; j++){
            if(num[j][i] == 0)
                val++;
        }
        if(val == 4)
            return true;
    }

    return false;
}

bool checkD(int num[][4]){
    int val = 0;
    for(int i = 0; i < 4; i++){
        if(num[i][i] == 0)
            val++;
    }
    if(val == 4)
        return true;

    val = 0;
    for(int i = 0; i < 4; i++){
        if(num[i][3-i] == 0)
            val++;
    }
    if(val == 4)
        return true;

    return false;
}

bool isLine(int ary[][4]){
    return checkH(ary) || checkV(ary) || checkD(ary);
}
