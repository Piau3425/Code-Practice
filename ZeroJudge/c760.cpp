#include <iostream>
using namespace std;

int main(){
    string input;
    while(cin >> input){
        input[0] -= 32;
        cout << input << '\n';
    }
}