#include <bits/stdc++.h>
using namespace std;

long long n(long long x) {
    if (x == 1) return 1;
    else return n(x-1) + x*x - x + 1;
}

int main() {
    int x;
    cin >> x;
    cout << n(x);
}