#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() { ios::sync_with_stdio(0); cin.tie(0);
    int n, tmp, sum = 0;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        cin >> tmp;
        sum += tmp;
    }
    cout << (1 + n)*n / 2 - sum;
}