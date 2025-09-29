#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;
    cout << input[0];
    for(int i = 1; i < input.length(); i++)
        cout << "-" << input[i];
}