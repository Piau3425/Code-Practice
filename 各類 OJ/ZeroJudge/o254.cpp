#include <bits/stdc++.h>
using namespace std;

#define WA() cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main() { WA();
    int a, b;
    cin >> a >> b;
    cout << (a > b)*a + (b >= a)*(b+1);
}