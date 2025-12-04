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

int p;

int fast_pow(int a, int b) {
    int sum = 1;
    for (; b; b >>= 1) {
        if (b&1) sum = sum*a%p;
        a = a*a%p;
    }
    return sum%p;
}

signed main() { WA();
    int n; cin >> n >> p;
    while (n--) {
        int t; cin >> t;
        cout << fast_pow(t, p-2) << ' ';
    }
}