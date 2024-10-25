#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v, bit;
int n;

void add(int idx, int val) {
    for (; idx <= n; idx += idx&-idx) bit[idx] += val;
}

int get(int start, int end) {
    int a = 0, b = 0;
    start--;
    for (; start > 0; start -= start&-start) a += bit[start];
    for (; end > 0; end -= end&-end) b += bit[end];
    return b-a;
}

void build() {
    bit.resize(n+1, 0);
    for (int i = 0; i < n; i++) add(i+1, v[i]);
}

signed main() { ios::sync_with_stdio(0); cin.tie(0);
    int t, i;
    for (cin >> t, i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        cin >> n;
        v.resize(n);
        for (auto &i : v) cin >> i;
        build();
        //for (auto i : bit) cout << i << ' ';
        //return 0;
        string cmd;
        int a, b;
        while (cin >> cmd) {
            if (cmd == "End") break;
            cin >> a >> b;
            if (cmd == "Query") cout << get(a, b) << '\n';
            else if (cmd == "Add") add(a, b);
            else if (cmd == "Sub") add(a, -b);
        }
        v.clear(); bit.clear();
    }
}