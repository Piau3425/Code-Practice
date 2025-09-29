#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    for(int i = a; i != b+c; i += c)
        cout << i << " ";
}