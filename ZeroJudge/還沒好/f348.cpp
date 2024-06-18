#include <iostream>
#include <cmath>
using namespace std;

//這題寫得有點醜

int p(int n){
    int x = 1;
    for(int i = 0; i < n; i++)
        x *= 10;
    
    return x;
}

int main(){
    int input, mul = 0, unP, dist = 0, diff, backup1, backup2, rev = 0,;
    cin >> input;
    backup1 = backup2 = input;

    while(backup1){ // 向上找偶數
        if((backup1%10) & 1){
            diff = p(mul) - input % p(mul);
            input += diff;
            dist += diff;
        }
        mul++;
        backup1 = input / p(mul);
    }

    mul = 0;
    while(backup2){ // 向下找偶數
        if((backup2%10) & 1){
            diff = p(mul);
            dist += diff;
        }
    }

    cout << dist;
}