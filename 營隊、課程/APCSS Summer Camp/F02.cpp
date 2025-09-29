#include <bits/stdc++.h>
using namespace std;

#define int long long

int ans = 1e9, n;
vector<int> v;

void f(int idx, int a, int b) {
    if (idx == n) return void(ans = min(abs(a-b), ans));

    f(idx+1, a+v[idx], b);
    f(idx+1, a, b+v[idx]);
}

signed main() { ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    v.resize(n);
    for (auto &i : v) cin >> i;

    f(0, 0, 0);
    cout << ans;
}