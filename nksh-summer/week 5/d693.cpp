#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b) {
    return abs(a * b) / __gcd(a, b);
}

int main() {
    long long n, a, b;

    while (cin >> n && n != 0) {
        cin >> a;
        for (int i = 0; i < n-1; i++) {
            cin >> b;
            a = lcm(a, b);
        }

        cout << a << '\n';
    }
}
