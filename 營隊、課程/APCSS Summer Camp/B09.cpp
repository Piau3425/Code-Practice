#include <bits/stdc++.h>

using namespace std;
int main(){
    long long a, b;
    cin >> a >> b;
    if (a == b) a -= 3;
    if (a > b) swap(a, b);
    if (b-a < a) cout << b-a << '+' << a << '=' << b;
    else cout << a << '+' << b-a << '=' << b;
}