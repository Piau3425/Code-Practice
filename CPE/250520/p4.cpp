#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 1000000+1

signed main() {
    vector<int> p(N, 1), ps; p[0] = p[1] = 0;
    for (int i = 2; i < N; i++) if (p[i]) for (int j = i*i; j < N; j += i) p[j] = 0;
    for (auto &i : p) if (i) ps.push_back(&i-p.data());

    int n;
    while (cin >> n, n) for (auto &i : ps) if (p[n-i]) {
        cout << n << " = " << i << " + " << n-i << '\n';
        break;
    }
}