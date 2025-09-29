#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v[max(0, i-a+1)]++;
            v[i+1]--;
        }

        int cur = 0;
        for (auto i : v) {
            cur += i;
            if (cur) cout << 1 << ' '; else cout << 0 << ' ';
        }
        cout << '\n';
    }
}