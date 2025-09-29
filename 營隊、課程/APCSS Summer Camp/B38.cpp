#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, mul = 4;
        cin >> n;
        while (n > mul) {
            n -= mul;
            mul += 4;
        }
        string s[] = {"Pen", "Pineapple", "Apple", "Pineapple pen"};
        cout << s[(n-1) / (mul/4)] << '\n';
    }
}