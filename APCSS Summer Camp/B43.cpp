#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, a, t;
    cin >> m >> a;
    while (m--) {
        cin >> t;
        if (a > t) a += t;
        else break;
    }
    cout << a;
}