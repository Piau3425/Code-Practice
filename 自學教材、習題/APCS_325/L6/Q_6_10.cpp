#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, m, s, sum = 0; cin >> n >> m >> s;
    vector<int> v(n);
    for (auto &i : v) cin >> i, sum += i;
    s = s-(m-sum);
    if (s <= 0) return cout << 0, 0;
    bitset<999999> dp;
    dp[0] = 1;
    for (auto &i : v) dp |= (dp << i);
    for (int i = s; i <= sum; i++) if (dp[i]) {
        cout << i;
        break;
    }
}