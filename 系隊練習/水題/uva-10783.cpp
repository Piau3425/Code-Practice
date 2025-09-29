#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n; cin >> n;
    for (int t = 1; t <= n; t++) {
        int a, b, sum = 0; cin >> a >> b; if (a > b) swap(a, b);
        for (int i = a; i <= b; i++) if (i&1) sum += i;
        cout << "Case " << t << ": " << sum << '\n';
    }
}