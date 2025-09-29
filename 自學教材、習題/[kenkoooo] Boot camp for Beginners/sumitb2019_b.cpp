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

signed main() { WA();
    double n; cin >> n;
    int x = n / 1.08;
    string s = ":(";
    for (int i = -1; i <= 1; i++) if ((int)((x+i)*1.08) == n) s = to_string(x+i);
    cout << s;
}