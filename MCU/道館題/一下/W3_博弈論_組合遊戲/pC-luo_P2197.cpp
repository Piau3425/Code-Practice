#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, t, e;
    cin >> n;
    while (n--) {
        cin >> e;
        int sum = 0;
        while (e--) cin >> t, sum ^= t;
        if (sum) cout << "Yes\n";
        else cout << "No\n";
    }
}