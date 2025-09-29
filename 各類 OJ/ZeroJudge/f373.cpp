#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n-(n/2000)*200 <= n-(n/1000)*100) cout << n-(n/2000)*200 << " 0";
    else cout << n-(n/1000)*100 << " 1";
}