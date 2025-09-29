#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string input;
    int odd = 0, even = 0;
    cin >> input;
    reverse(input.begin(), input.end());
    for(int i = 0; i < input.length(); i++){
        if((i+1) & 1)
            odd += input[i] - '0';
        else
            even += input[i] - '0';
    }

    cout << abs(odd-even);
}