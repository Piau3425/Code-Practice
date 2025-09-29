#include <iostream>
using namespace std;

#define WA() ios_base::sync_with_stdio(false);

signed main() { WA();
    int t, n; cin >> t;
    
    while (t--) {
        int a, b, e, cnt = 0; a = b = 1e9;
        cin >> n;
        while (n--) {
            cin >> e;
            if (e < a) a = e;
            else if (e < b) b = e, cnt++;
        }
        cout << cnt << '\n';
    }
}