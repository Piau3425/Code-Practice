// 先塞一個之前寫過的 BIT

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) ((x)&-(x))

vector<int> v, bit;
int n;

void add(int idx, int val) {
    for (; idx <= n; idx += lowbit(idx)) bit[idx] += val;
}

int get(int start, int end) {
    int a = 0, b = 0;
    start--;
    for (; start > 0; start -= lowbit(start)) a += bit[start];
    for (; end > 0; end -= lowbit(end)) b += bit[end];
    return b-a;
}

signed main() { ios::sync_with_stdio(0); cin.tie(0);
    int t, i;
    for (cin >> t, i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        cin >> n;
        v.resize(n);
        for (auto &i : v) cin >> i;
        bit.resize(n+1, 0);
        for (int i = 0; i < n; i++) add(i+1, v[i]);
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