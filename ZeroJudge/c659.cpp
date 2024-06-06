#include <iostream>
using namespace std;

int main(){
    string conj, input;
    cin >> conj >> input;
    cout << input;
    while(cin >> input)
        cout << " " << conj << " " << input;
}