#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n; cin >> n;
    for (int i = 0; i < (1<<n); i++) {
        string s;
        for (int j = i^(i>>1); j; j>>=1) s += (j&1)+'0';
        cout << setfill('0') << setw(n) << string(s.rbegin(), s.rend()) << '\n';
    }
}