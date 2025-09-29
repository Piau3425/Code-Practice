#include <iostream>
using namespace std;

int total = 0, ct;

int main(){
    cin >> ct;
    total += ct*60;
    cin >> ct;
    total += ct;

    if(total < 1020 && total >= 450)
        cout << "At School";
    else
        cout << "Off School";
}
