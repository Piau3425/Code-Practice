#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans = 1e9, n, ans2;
vector<int> v;

void f(int idx, int a, int b, int sa, int sb) {
    if (idx == n) {
        if (abs(a-b) < ans) {
            ans2 = min(sa, sb);
            ans = abs(a-b);
        }
        return;
    }

    f(idx+1, a+v[idx], b, sa+1, sb);
    f(idx+1, a, b+v[idx], sa, sb+1);
}

signed main() { 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(a/b);
    }
    f(0, 0, 0, 0, 0);
    cout << ans << '\n' << ans2 << '\n';
}