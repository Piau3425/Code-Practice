#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string input;
        int sumA = 0, sumB;
        cin >> input;
        for(int j = 0; j <= 2; j++){
            sumA += (input[j]-'A')*pow(26, 2-j);
        }   
        sumB = stoi(input.substr(4, 7));
        abs(sumA - sumB) <= 100 ? cout << "nice\n" : cout << "not nice\n";
    }
}