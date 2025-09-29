#include <iostream>
using namespace std;

int main(){
    int n, input, total = 0;
    cin >> n;
    while(n--){
        cin >> input;
        total += (input <= 10);
    }
    cout << total;
}