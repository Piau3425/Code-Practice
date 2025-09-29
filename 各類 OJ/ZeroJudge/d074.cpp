#include <iostream>
using namespace std;

int classs, maxx, amount;

int main(){
    cin >> classs;
    for(int i = 0; i < classs; i++){
        cin >> amount;
        maxx = max(maxx, amount);
    }

    cout << maxx;
}
