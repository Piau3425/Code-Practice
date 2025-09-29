#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;
    cout << input << " little";
    while(cin >> input)
        cout << ", " << input << " little";
    cout << " Indians";
}