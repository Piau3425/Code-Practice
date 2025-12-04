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
    int N, i, j, G;
    while (cin >> N, N) {
        G = 0;
        for (i=1; i<N; i++) for (j=i+1; j<=N; j++) {
            G += __gcd(i,j);
        }
        cout << G << '\n';
    }
}