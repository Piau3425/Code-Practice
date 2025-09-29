#include <bits/stdc++.h>
using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int k, n, m, x, y;
    while (cin >> k && k) {
        cin >> n >> m;
        while (k--) {
            cin >> x >> y;
            if (x > n && y > m) cout << "NE\n";
            else if (x < n && y > m) cout << "NO\n";
            else if (x > n && y < m) cout << "SE\n";
            else if (x < n && y < m) cout << "SO\n";
            else cout << "divisa\n";
        }   
    }
}