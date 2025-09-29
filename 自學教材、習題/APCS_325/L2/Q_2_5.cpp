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

int p = 1000000007;

#define vvi vector<vector<int>>
vvi MaT(vvi a, vvi b) {
    vvi c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] += a[i][k] * b[k][j] % p;
            }
        }
    }
    return c;
}

int f(int x) {
    vector<vector<int>> a = {{1, 1}, {1, 0}};
    vector<vector<int>> sum = {{1, 0}, {0, 1}};
    for (; x; x >>= 1) {
        if (x&1) sum = MaT(sum, a);
        a = MaT(a, a);
    }
    return sum[0][1] % p;
}

signed main() { WA();
    int n;
    while (cin >> n, n != -1) cout << f(n) << '\n';
}