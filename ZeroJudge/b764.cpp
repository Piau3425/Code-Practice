#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    set<string> check{"00", "01", "100", "101", "1100", "1101", "11100", "11101", "111100", "111101", "111110", "111111"};
    map<string, char> bit2char = {
        {"00", 'A'},
        {"01", 'B'},
        {"100", '0'},
        {"101", '1'},
        {"1100", '2'},
        {"1101", '3'},
        {"11100", '4'},
        {"11101", '5'},
        {"111100", '6'},
        {"111101", '7'},
        {"111110", '8'},
        {"111111", '9'},
    };

    int n;
    while(cin >> n){
        while(n--){
            string input, tmp = "", output = "";
            cin >> input;
            for(int i = 0; i < input.length(); i++){
                tmp += input[i];
                if(check.count(tmp)){
                    output +=  bit2char[tmp];
                    tmp = "";
                }
                if(output.length() == 4)
                    output += ',';
            }
            cout << output + '\n';
        }
    }
}