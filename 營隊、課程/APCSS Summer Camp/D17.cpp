#include <bits/stdc++.h>
using namespace std;


template<class IT>
IT lcm(IT a, IT b) {
    return abs(a*b) / __gcd(a, b);
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << lcm(lcm(a, b), c);
}