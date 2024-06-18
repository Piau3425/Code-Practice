#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int sum = 0, idx, mul = 0;
    string input, eng = "", num = "";

    cin >> input;

    for(idx = 0; isalpha(input[idx]); idx++)
        eng += input[idx];
    for(; idx < input.length(); idx++)
        num += input[idx];
    
    for(int j = 0; j < eng.length(); j++)
        sum += (eng[j] - 'A' + 1) * pow(26, eng.length() - 1 - j);
    for(int j = 0; j < num.length(); j++){
        mul *= 10;
        mul += num[j] - '0';
    }
    
    sum *= mul;

    cout << sum;
}