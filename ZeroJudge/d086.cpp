#include <iostream>
using namespace std;

int main(){
    string input;
    while(cin >> input && input != "0"){
        int score = 0, i;
        for(i = 0; i < input.length(); i++){
            if(!isalpha(input[i])){
                cout << "Fail\n";
                break;
            }
            if(islower(input[i]))
                input[i] -= 32;
            score += input[i] - 'A' + 1;
        }
        
        if(i == input.length())
            cout << score << '\n';
    }
}