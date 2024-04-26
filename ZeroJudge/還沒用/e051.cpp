#include <iostream>
using namespace std;

int main(){
    string input, tmp = "";
    cin >> input;
    for(int i = 0; i < input.length() -2; i++)
        tmp += '_';
    input.replace(input.begin()+1, input.end()-1, tmp);
    cout << input;
}