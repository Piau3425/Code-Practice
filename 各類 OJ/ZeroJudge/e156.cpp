#include <iostream>
using namespace std;

int sum = 0;

int f(int n) {
    sum += n;
    return n && f(n-1);
}

int main() {
    int m;
    cin >> m;
    f(m);
    cout << sum;
}