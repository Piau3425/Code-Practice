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
    int n; //while (cin >> n, ~n) cout << n*(n+1)*(2*n+1)/6 << '\n';
    while (~scanf("%lld", &n) && n != -1) printf("%lld\n", n*(n+1)*(2*n+1)/6); 
}