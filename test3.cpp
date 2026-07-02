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
    vector<vector<double>> v(n, vector<double>(n+1));
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int k = 0; k+1 < n; k++) {
        for (int i = k+1; i < n; i++) {
            double fac = v[i][k]/v[k][k];
            for (int j = k; j <= n; j++) v[i][j] -= fac * v[k][j];
        }
    }
    for (auto &i : v) {
        for (auto &j : i) cout << setw(5) << j << ' ';
        cout << '\n';
    }

    vector<double> x(n);
    for (int i = n-1; i >= 0; i--) {
        double sum = 0;
        for (int j = i+1; j < n; j++) sum += v[i][j]*x[j];
        x[i] = (v[i].back()-sum)/v[i][i];
    }
    for (auto &i : x) cout << i << ' ';
}