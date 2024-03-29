#include <iostream>
using namespace std;

int a, b;

int main(){
    cin >> a >> b;

    if(b == 0 || a%b == 0)
        cout << "OK!";
    else
        cout << a%b;
}
