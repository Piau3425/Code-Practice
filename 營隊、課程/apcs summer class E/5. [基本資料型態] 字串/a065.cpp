#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string input;
int odd, even;

int main(){
    cin >> input;
    reverse(input.begin(), input.end());

    for(int i = 0; i < input.size(); i++){
        if((i+1)%2 == 0)
            even += input[i]-'0';
        else
            odd += input[i]-'0';
    }
    cout << abs(odd-even);
}
