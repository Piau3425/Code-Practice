#include <iostream>
using namespace std;

int main(){
    int k, s;
    cin >> k >> s;
    if(!(s % k)){
        s /= k; k = 1;
    }

    int sum = k + s, t = 1, i = 0;
    for(; t != sum; i++)
        t += t;

    cout << i;
}