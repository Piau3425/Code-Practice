#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    for (cin >> n; n; n--) {
        string x, x2;
        int cnt = 0;
        cin >> x;
        do {
            cnt++;
            x2 = string(x.rbegin(), x.rend());
            x = to_string(stoll(x)+stoll(x2));
        } while (x != string(x.rbegin(), x.rend()));
        cout << cnt << ' ' << x << endl;
    }
}