#include <bits/stdc++.h>
using namespace std;

#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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