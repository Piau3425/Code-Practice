#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        if (!(t%3) && !(t%2)) cout << 1;
        else if ((t%10)&1 && t%3) cout << 2;
        else if (sqrt(t) == (int)sqrt(t) || t%7 && !(t&1)) cout << 3;
        else cout << 0;
        cout << ' ';
    }
}