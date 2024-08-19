#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, ms = 0, ns = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        ms += tmp;
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ns += tmp;
    }
    if (m > n && ms > ns) cout << "Yes";
    else cout << "No";
}