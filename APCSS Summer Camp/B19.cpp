#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, y;
    cin >> t;
    while(t--) {
        cin >> y;
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            cout << "a leap year" << endl;
        } else {
            cout << "a normal year" << endl;
        }
    }
}