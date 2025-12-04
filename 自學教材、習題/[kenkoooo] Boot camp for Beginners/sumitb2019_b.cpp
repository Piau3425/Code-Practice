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
    double n; cin >> n;
    int x = n / 1.08;
    string s = ":(";
    for (int i = -1; i <= 1; i++) if ((int)((x+i)*1.08) == n) s = to_string(x+i);
    cout << s;
}