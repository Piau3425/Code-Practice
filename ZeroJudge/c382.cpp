#include <iostream>
using namespace std;

int main(){
    char op;
    int a, b;
    cin >> a >> op >> b;
    switch(op){
        case '+':
            cout << a+b;
            break;
        case '-':
            cout << a-b;
            break;
        case '*':
            cout << a*b;
            break;
        case '/':
            cout << a/b;
            break;
    }
}