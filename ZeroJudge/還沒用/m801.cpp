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
    
    /*stack<char> tmp = s;
    for(; !s.empty();){
        cout << tmp.top();
        tmp.pop();
    }*/

    if(input == string(input.rbegin(), input.rend()))
        cout << "Yes";
    else
        cout << "No";
}