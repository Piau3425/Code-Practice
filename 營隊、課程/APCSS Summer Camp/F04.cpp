#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q, mx = 0;
    cin >> n >> k >> q;
    vector<int> v(n, k);
    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        v[tmp-1]++;
    }

    for (auto i : v) if (i - q > 0) cout << "Yes\n"; else cout << "No\n";
}