#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){
    string input;
    int tmp;
    while(cin >> input && input != "0"){
        if(input.length() <= 2 && stoi(input) < 11){
            cout << input << " is not a multiple of 11.\n";
            continue;
        }
        string s2 = input;
        for(int i = 0; i < input.length()-1; i++){
            int tmp = stoi(input.substr(i, 2));
            input[i] = (tmp%11)/10 + '0';
            input[i+1] = (tmp%11)%10 + '0';
            //cout << input << endl;
        }

        regex re("[^0]");
        cout << s2 << " is" << (regex_search(input, re) ? " not " : " ") << "a multiple of 11.\n";
    }
}