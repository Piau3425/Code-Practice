#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n;
        
        while (cin >> m && m) {
			if (!n) n = 10000;
            if (n >= 10 && n <= 99) n -= m;
            else if (n >= -99 && n <= -10) n += m;
            else if (abs(n) >= 100) n /= m;
            else if (abs(n) >= 1 && abs(n) <= 9) n *= m;
        }
        cout << n << '\n';
    }
}