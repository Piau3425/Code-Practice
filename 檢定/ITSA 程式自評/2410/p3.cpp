#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for (auto &i : v) cin >> i;
    for (int i = 1; i+1 < n; i++) {
        if (v[i] > v[i-1] && v[i] > v[i+1]) s.insert(i);
    }

    cout << s.size() << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (s.count(i)) cout << ">>>>>";
        cout << '\n';
    }
}