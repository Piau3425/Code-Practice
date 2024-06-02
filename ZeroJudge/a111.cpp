#include <iostream>
using namespace std;

int main(){
    int sum, input;
    while(cin >> input && input != 0){
        sum = 0;
        input++;
        while(input--)
            sum += input*input;
        cout << sum << '\n';
    }
}