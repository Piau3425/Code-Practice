#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> v(n);
    
    for (auto &i : v) cin >> i;

    int ldx = 0, rdx = 0;
    unordered_set<int> s;
    s.insert(v[ldx]);
    while (ldx < rdx) {
        cout << ldx << ' ' << rdx << " : " << s.size() << '\n';
        for (auto i : s) cout << i << ' ';
        cout << '\n';
        if (s.size() > x && ldx+1 < n) {
            s.erase(s.find(v[ldx]));
            ldx++;
            s.insert(v[ldx]);
        }
        else if (s.size() < x && rdx+1 < n) {
            rdx++;
            s.insert(v[rdx]);
        }
        else if (rdx+1 < n) {
            ans++;
            rdx++;
            s.insert(v[rdx]);
        }
    }

    cout << ans;
}