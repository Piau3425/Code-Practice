#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, sum = 0;
  	cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        sum += p*i;
    }
    cout << sum;
}