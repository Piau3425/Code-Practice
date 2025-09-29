//或許計算壘包上跑者移動時，可以使用rotate函式

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    vector<string> player[9];
    int score = 0, out = 0, target;
    bool bao[4];
    memset(bao, false, sizeof(bao));


    for(int i = 0; i < 9; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            string tmp;
            cin >> tmp;
            player[i].push_back(tmp);
        }
    }

    /*string blank;
    cin.ignore();
    getline(cin, blank);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < player[i].size(); j++){
            cout << player[i][j] << " ";
        }
        cout << endl;
    }*/


    cin >> target;
    for(int p = 0, r = 0; out != target; p++){
        if(p == 9){
            r++;
            p = 0;
        }

        if(player[p][r][1] == 'O'){
            out++;
            if(out%3 == 0)
                memset(bao, false, sizeof(bao));
        }
        else{
            int hr;
            if(player[p][r][1] == 'B')
                hr = player[p][r][0]-'0';
            else
                hr = 4;
            //cout << "------- " << r << " " << p << " " << player[p][r][0] << " " << hr << endl;
            for(int i = 0; i < hr; i++){
                for(int j = 3; j >= 1; j--){
                    bao[j] = bao[j-1];
                }
                if(i == 0)
                    bao[0] = true;
                else
                    bao[0] = false;

                if(bao[3])
                    score++;
            }

            /*for(int i = 0; i < 4; i++){
                if(bao[i])
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;*/
        }
    }

    cout << score;
}
