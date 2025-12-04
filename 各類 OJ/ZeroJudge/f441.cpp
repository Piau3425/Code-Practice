#include <bits/stdc++.h>
using namespace std;

#define WA() cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main() { WA();
    int a, b; cin >> a >> b;
    vector<int> ans(a);
    for (auto &i : ans) cin >> i;

    int n, sum = 0; cin >> n;
    while (n--) {
        int sum = 0, g;
        for (auto &i : ans) {
            cin >> g;
            sum += (i == g)*b;
        }
        cout << sum << '\n';
    }
}