#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i <= m; i++) {
        if (x*i + y*(m-i) == n) {
            cout << i << ' ' << m-i;
            return 0;
        }
    }

    cout << "-1 -1";
}