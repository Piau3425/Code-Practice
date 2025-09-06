#include <bits/stdc++.h>
using namespace std;

#define se second
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define lowbit(x) x&-x

int n;
vector<int> bit, v;

void update(int x) {
    for (; x <= n; x += x&-x) bit[x]++;
}

int query(int x) {
    int sum = 0;
    for (; x; x -= x&-x) sum += bit[x];
    return sum;
}

signed main() { WA();
    while (cin >> n, n) {
        int ans = 0;
        bit.assign(n+1, 0);
        v.assign(n, 0);
        map<int, int> mp;
        int des = 1;
        for (auto &i : v) cin >> i;
        for (auto &i : v) mp[i]++;
        for (auto &i : mp) i.se = des++;
        for (auto &i : v) i = mp[i];

        for (int i = 0; i < n; i++) {
            ans += i - query(v[i]);
            update(v[i]);
        }

        cout << ans << '\n';
    }
}