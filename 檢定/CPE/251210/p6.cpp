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

int N = 501, P = 1e6+7;

signed main() { WA();
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0, j; i < N; i++) {
        for (C[i][0] = C[i][i] = 1, j = 1; j < i; j++) {
             C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
        }
    }
    int t, T = 0; for (cin >> t; t--;) {
        int n, m, k; cin >> n >> m >> k;
        cout << "Case " << ++T << ": ";
        cout << ((C[m*n][k] - 2*C[(m-1)*n][k]
                            - 2*C[m*(n-1)][k]
                            + C[(m-2)*n][k]
                            + C[m*(n-2)][k]
                            + 4*C[(m-1)*(n-1)][k]
                            - 2*C[(m-2)*(n-1)][k]
                            - 2*C[(m-1)*(n-2)][k]
                            + C[(m-2)*(n-2)][k]) % P + P) % P << '\n';
    }
}