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
#define vii vector<vector<int>>

int mod = 1e9+7;

vii mat(vii a, vii b, int p) {
    vii c = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] = (c[i][j] + a[i][k]*b[k][j])%p;
            }
        }
    }
    return c;
}

int f(int x, int p) {
    vii sum = {{1, 0}, {0, 1}}, a = {{1, 1}, {1, 0}};
    for (; x; x >>= 1) {
        if (x&1) sum = mat(sum, a, p);
        a = mat(a, a, p);
    }
    return sum[0][1];
} 

int fast_pow(int a, int b) {
    a = f(a, mod); b = f(b, mod-1);
    int sum = 1;
    for (; b; b >>= 1) {
        if (b&1) sum = sum*a%mod;
        a = a*a%mod;
    }
    return sum%mod;
}

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << fast_pow(a, b)%mod << '\n';
    }
}