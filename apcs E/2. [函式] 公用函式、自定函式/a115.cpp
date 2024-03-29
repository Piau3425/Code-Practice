#include <iostream>
using namespace std;

int checkH(int x, int num[][5]);
int checkV(int x, int num[][5]);
int checkD(int x, int num[][5]);
int calScore(int x, int num[][5]);

int main(){
    int score, choose, num[5][5], ans[2] = {999, 0};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> num[i][j];
        }
    }

    while(1){
        cin >> choose;
        if(choose == -1)
            break;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(choose == num[i][j]){
                    num[i][j] = 0;
                }
            }
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(num[i][j] == 0)
                continue;
            score = calScore(num[i][j], num);
            //cout << "score = " << score << endl;;
            if(score > ans[1] ||(score == ans[1] && num[i][j] < ans[0])){
                ans[0] = num[i][j];
                ans[1] = score;
            }
        }
    }

    cout << ans[0];
}

int checkH(int x, int num[][5]){
    int score = 0;
    for(int i = 0; i < 5; i++){
        int val = 0;
        for(int j = 0; j < 5; j++){
            if(num[i][j] == 0 || num[i][j] == x)
                val++;
        }
        if(val == 5)
            score++;
    }

    return score;
}

int checkV(int x, int num[][5]){
    int score = 0;
    for(int i = 0; i < 5; i++){
        int val = 0;
        for(int j = 0; j < 5; j++){
            if(num[j][i] == 0 || num[j][i] == x)
                val++;
        }
        if(val == 5)
            score++;
    }

    return score;
}

int checkD(int x, int num[][5]){
    int score = 0, val = 0;
    for(int i = 0; i < 5; i++){
        if(num[i][i] == 0 || num[i][i] == x)
            val++;
    }
    if(val == 5)
        score++;

    val = 0;
    for(int i = 0; i < 5; i++){
        if(num[i][4-i] == 0 || num[i][4-i] == x)
            val++;
    }
    if(val == 5)
        score++;

    return score;
}

int calScore(int x, int num[][5]){
    //cout << checkH(x, num) << " " << checkV(x, num) << " " << checkD(x, num) << endl;
    return checkH(x, num) + checkV(x, num) + checkD(x, num);
}
