#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int x, int sum) {
    if (x == 1) return sum;
    if (x&1) return f(x*3+1, ++sum);
    else return f(x/2, ++sum);
}

signed main() {
    int n;
    cin >> n;
    cout << f(n, 0);
}