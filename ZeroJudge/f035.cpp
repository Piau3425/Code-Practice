#include <iostream>
using namespace std;

int main(){
    string input;
    getline(cin, input);
    cout << (int)input[0];
    for(int i = 1; i < input.length(); i++)
        cout << "_" << (int)input[i];
}