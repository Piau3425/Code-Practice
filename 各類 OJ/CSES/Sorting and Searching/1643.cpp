#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n, i, sum = 0, mx = -1e9;
    cin >> n;

    while (n--) {
        cin >> i;
        sum += i;
        mx = max(mx, sum);
        if (sum < 0) sum = 0;
    }
    cout << mx;
}