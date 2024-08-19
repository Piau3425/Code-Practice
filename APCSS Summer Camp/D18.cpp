#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << (((a+1)/2)*2+((b/2)*2))/2*((b-a)+!(a&1)+!(b&1))/2;
}