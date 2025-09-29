#include <iostream>

using namespace std;

int a, b, A_total, B_total, win = 0;

int main(){
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 4; i++){
            cin >> a;
            A_total += a;
        }

        for(int i = 0; i < 4; i++){
            cin >> b;
            B_total += b;
        }

        if(A_total > B_total)
            win++;
        else if(A_total < B_total)
            win--;

        cout << A_total << ":" << B_total << endl;

        A_total = 0;
        B_total = 0;
    }

    if(win == 2)
        cout << "Win";
    else if(win == -2)
        cout << "Lose";
    else
        cout << "Tie";
}
