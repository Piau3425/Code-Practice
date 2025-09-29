#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n = 5, score = 0, t[3];
    while(n--){
        for(int i = 0; i < 3; i++)
        cin >> t[i];

        sort(t, t+3);

        if(t[0]+t[1] > t[2])
            score++;
    }

    cout << score;
}