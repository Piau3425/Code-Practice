#include <iostream>
using namespace std;

int main(){
    int year;

    while(true){
        cin >> year;
        if(year == 0) {
            break;
        }

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            cout << "a leap year" << endl;
        } else {
            cout << "a normal year" << endl;
        }
    }
}
