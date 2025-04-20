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
    int N, i, j, G;
    while (cin >> N, N) {
        G = 0;
        for (i=1; i<N; i++) for (j=i+1; j<=N; j++) {
            G += __gcd(i,j);
        }
        cout << G << '\n';
    }
}