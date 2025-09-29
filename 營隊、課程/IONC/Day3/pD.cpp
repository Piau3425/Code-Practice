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
#define MAXN 100000

int f(int x, int y, int p) {
    int sum = 1;
    while (y > 0) {
        if (y&1) sum = sum*x%p;
        x = x*x%p;
        y >>= 1;
    }
    return sum%p;
}

signed main() { WA();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << f(i, i, i+1) << '\n';
    }
}