#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int ldx = j+1, rdx = n-1;
            while (ldx < rdx) {
                int sum = v[i] + v[j] + v[ldx] + v[rdx];
                if (sum < x) ldx++;
                else if (sum > x) rdx--;
                else {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }

    cout << "NO";
}