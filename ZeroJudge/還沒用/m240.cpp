#include <iostream>
using namespace std;

int main(){
    int t, sum = 0;
    cin >> t;
    for(int i = 0; i < t; i++){
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    cout << sum;
}
