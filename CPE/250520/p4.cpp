#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 1000000+1

signed main() {
    vector<int> p(N, 1); p[0] = p[1] = 0;
    for (int i = 2; i < N; i++) {
        if (p[i]) for (int j = i*i; j < N; j += i) p[j] = 0;
    }
    set<int> ps;
    for (auto &i : p) if (i) ps.insert(&i-p.data());

    int n;
    while (cin >> n, n) {
        int flag = 1;
        for (auto &i : ps) if (ps.count(n-i)) {
            cout << n << " = " << i << " + " << n-i << '\n';
            flag = 0;
            break;
        }
        flag && cout << "Goldbach's conjecture is wrong.\n";
    }
}