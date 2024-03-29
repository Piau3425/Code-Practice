#include <iostream>
using namespace std;

int year, t;

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> year;
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            cout << "Case " << i+1 << ": a leap year" << endl;
        else
            cout << "Case " << i+1 << ": a normal year" << endl;
    }
}
