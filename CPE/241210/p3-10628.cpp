#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

signed main() {
    string s; int x, n;
    while (cin >> x) {
        cin.ignore();
        getline(cin, s);
        stringstream ss(s);
        vector<int> v;
        while (ss >> n) v.pb(n);
        v.pop_back();

        double sum = 0; n = v.size();
        for (int i = 0; i < n; i++) {
            sum *= x;
            sum += v[i]*(n-i);
        }
        cout << (int)sum << '\n';
    }
}