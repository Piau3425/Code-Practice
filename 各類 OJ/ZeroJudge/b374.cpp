#include <iostream>
using namespace std;

int ary[30000] = {0};

int main(){
    int total, input, maxx = -1e9;;
    cin >> total;
    for(int i = 0; i < total; i++){
        cin >> input;
        ary[input-1]++;
        maxx = max(maxx, ary[input-1]);
    }

    for(int i = 0; i < 30000; i++){
        if(ary[i] == maxx)
            cout << i+1 << " " << ary[i] << '\n';
    }
}