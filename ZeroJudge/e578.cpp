#include <iostream>
using namespace std;

int main(){
    string decode = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char input;
    while(cin.get(input) && !cin.eof())
        input == '\n' || input == ' ' ? cout << input : cout << decode[decode.find(input)-2];
    
}