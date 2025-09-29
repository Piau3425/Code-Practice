#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    int ldx = 0, rdx = n-1;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());

    while (ldx <= rdx) {
        cout << ldx << ' ' << rdx << '\n';
        if (v[ldx] + v[rdx] <= x) {
            ldx++; rdx--;
        }
        else rdx--;
        ans++;
    }

    cout << ans;
}