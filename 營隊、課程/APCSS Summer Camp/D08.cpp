#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, q, m;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    while (q--) {
        cin >> m;
        if(m-1) for (int i = 0; i < v.size(); i++) cout << v[i] << " \n"[i+1 == v.size()];
        else  {
            for (int i = 0; i+1 < v.size(); i++) v[i] += v[i+1];
            v.resize(v.size()-1);
        }
    }
}