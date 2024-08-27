#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--) {
        int a, b, c, f = 1;
        cin >> a >> b >> c;
        for (int i = a+1; i < b; i++) if (i%c) {
            cout << (!f ? " " : "") << i;
            f = 0;
        }
        if (f) cout << "No free parking spaces.";
        cout << '\n';
    }
}