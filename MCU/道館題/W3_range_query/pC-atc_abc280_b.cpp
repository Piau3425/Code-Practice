#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> v(n+1, 0), ps(n+1, 0);
    for (int i = 1, prefix = 0, tmp; i <= n; i++) {
        cin >> tmp;
        v[i] = tmp-ps[i-1];
        prefix += v[i];
        ps[i] = prefix;
    }
    for (int i = 1; i <= n; i++) cout << v[i] << ' ';
}