#include <bits/stdc++.h>
using namespace std;

string isL(long long y) {
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0 ? "yes\n" : "no\n");
}

int main() {
    long long n;
    cin >> n;
    cout << isL(n) << isL(n+10) << isL(n+20);
}