#include <bits/stdc++.h>
using namespace std;

#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() { WA();
    int a, b;
    cin >> a >> b;
    cout << (a > b)*a + (b >= a)*(b+1);
}