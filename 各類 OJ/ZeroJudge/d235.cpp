#include <iostream>
using namespace std;

int main(){
    string input;
    while(cin >> input && input != "0"){
        int odd = 0, even = 0;
        for(int i = 0; i < input.length(); i++)
            ((i+1)&1 ? odd : even) += input[i] - '0';
        
        cout << input << " is" << ((!(abs(odd-even)%11)) ? " " : " not ") << "a multiple of 11.\n";
    }
}