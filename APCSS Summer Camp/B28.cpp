#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = n-1-i; j > 0; j--) cout << ' ';
            for (int j = 0; j < i+1; j++) cout << '*';
            cout << '\n';
        }
        cout << '\n';
    }
}