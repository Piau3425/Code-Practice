#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= d; j++) {
            if (n*i + m*j == d) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}