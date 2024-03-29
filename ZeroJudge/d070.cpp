#include <iostream>
using namespace std;

int year;

int main(){
    while(1){
        cin >> year;
        if(year == 0)
            break;
        else if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            cout << "a leap year" << endl;
        else
            cout << "a normal year" << endl;
    }
}
