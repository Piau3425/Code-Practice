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
    int d, a, b, n;
    double c;
    cin >> n;
    while (n--) {
        cin >> d >> a >> b >> c;
        cout << fixed << setprecision(2) << c*d/(a+b) << '\n';
    }
}