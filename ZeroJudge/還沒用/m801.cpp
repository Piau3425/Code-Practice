#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;
    string check = "AHIMOTUVWXY";

    for(int i = 0; i < input.length(); i++){
        if(check.find(input[i]) == string::npos){
            cout << "No";
            return 0;
        }
    }

    if(input == string(input.rbegin(), input.rend()))
        cout << "Yes";
    else
        cout << "No";
}