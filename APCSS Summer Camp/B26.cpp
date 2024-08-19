#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    while (cin >> n >> e && n+1) {
        int sum = n*e, ans = 0;
        if(n == 0 || e == 0) {
        	cout << "0\n";
        	continue;
        }
        while (sum >= 0) {
            sum -= sum/e+1;
            ans++;
        }
        cout << ans << '\n';
    }
}