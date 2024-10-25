#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, i, j;
    while(cin >> N && N) {
        int G=0;
        for (i=1; i<N; i++) for (j=i+1; j<=N; j++) {
            G += __gcd(i,j);
        }
        cout << G << '\n';
    }
}
