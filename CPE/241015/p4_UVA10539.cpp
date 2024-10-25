#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

signed main() {
    vector<int> p(1000000, 1), v;
    for (int i = 2; i <= 1000000; i++) if (p[i]) {
        for (int j = i*i; j <= 1000000; j += i) p[j] = 0;
        for (int j = i*i; j <= 1000000000000; j *= i) v.push_back(j);
    }
    sort(all(v));

    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << upper_bound(all(v), b) - lower_bound(all(v), a) << '\n';
    }
}