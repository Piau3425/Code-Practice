#include <bits/stdc++.h>
using namespace std;

int sum;

void f(int n) {
    if (n == 0 || n == 1) {
        cout << 1;
        return;
    }
    sum *= n;
    cout << n << " * ";
    return f(n-1);
}

int main() {
    int n;
    while (cin >> n) {
        sum = 1;
        cout << n << "! = ";
        f(n);
        cout << " = " << sum << '\n';
    }
}
