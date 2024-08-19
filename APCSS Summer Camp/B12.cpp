#include <bits/stdc++.h>
using namespace std;

int main(){
    double n;
    cin >> n;
    if (n != int(n)) cout << "X";
    else if (int(n)&1) cout << "Odd";
    else cout << "Even";
}