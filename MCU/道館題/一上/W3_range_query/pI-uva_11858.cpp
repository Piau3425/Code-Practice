#include <bits/stdc++.h>
using namespace std;

#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define lowbit(x) x&-x

int n;
vector<int> v, bit;

void update(int x) {
    for (; x <= n; x += lowbit(x)) bit[x] += 1;
}

int query(int x) {
    int sum = 0;
    for (; x > 0; x -= lowbit(x)) sum += bit[x];
    return sum;
}

signed main() { WA();
    while (cin >> n) {
        v.assign(n, 0);
        bit.assign(n+1, 0);
        for (auto &i : v) cin >> i;
        map<int, int> mp;
        int des = 1;
        for (auto &i : v) mp[i]++;
        for (auto &i : mp) i.se = des++;
        for (auto &i : v) i = mp[i];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i - query(v[i]);
            update(v[i]);
        }

        cout << ans << '\n';
    }
}