#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v, bit;
int n;

void update(int x, int y) {
    for (int i = x; i <= n; i += i&-i) bit[i] += y;
}

int query(int x) {
    int sum = 0;
    for (int i = x; i; i -= i&-i) sum += bit[i];
    return sum;
}

signed main() {
    for (; cin >> n, n;) {
        v.assign(n, 0);
        bit.assign(n+1, 0);
        for (auto &i : v) cin >> i;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += i - query(v[i]);
            update(v[i], 1);
        }
        cout << (cnt&1 ? "Marcelo" : "Carlos") << '\n';
    }
}