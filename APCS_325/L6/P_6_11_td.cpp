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

int dp[101], n, p = 1e9+9;

int f(int x) {
    if (~dp[x]) return dp[x];
    int sum = 0;
    for (int i = 0; i < x; i++) sum = (sum+f(i)*f(x-1-i)%p)%p;
    return dp[x] = sum;
}

signed main() { WA();
    fill(dp, dp+101, -1); dp[0] = 1;
    cin >> n;
    cout << f(n);
}