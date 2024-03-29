#include <iostream>
using namespace std;

int year;

int main(){
    cin >> year;
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        cout << "a leap year" << endl;
    else
        cout << "a normal year" << endl;
}
