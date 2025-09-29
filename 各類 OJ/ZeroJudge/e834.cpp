#include <iostream>
using namespace std;

int multi, buy;

int main(){
    cin >> multi;
    while(1){
        cin >> buy;
        if(buy == 0)
            return 0;

        if(buy%multi == 0)
            cout << buy/multi;
        else
            cout << multi-buy%multi;

        cout << endl;
    }
}
