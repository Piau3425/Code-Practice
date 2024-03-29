#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

bool check(int a, int b);

int main(){
    while(1){
        int N;
        cin >> N;
        if(N == 0)
            break;

        bool noAns = true;
        for(int i = 10000; i < 100000; i++){
            if(i%N == 0 && check(i, i/N)){
                printf("%05d / %05d = %d\n", i, i/N, N);
                noAns = false;
            }
        }

        if(noAns)
            cout << "There are no solutions for " << N << "." << endl;

        cout << endl;
    }
}

bool check(int a, int b){
    bool num[10];
    memset(num, true, sizeof(num));
    for(int i = 0; i < 5; i++, a/=10){
        int tmp = a%10;
        num[tmp] = false;
    }
    for(int i = 0; i < 5; i++, b/=10){
        int tmp = b%10;
        num[tmp] = false;
    }

    for(int i = 0; i < 10; i++){
        if(num[i])
            return false;
    }

    return true;
}
