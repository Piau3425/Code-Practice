#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int a, b;
    while (cin >> a >> b) {
        vector<int> v;
        if (a <= 1 || b <= 1) {
            cout << "Boring!\n";
            continue;
        }
        while (!(a%b)) {
            v.pb(a);
            a /= b;
        }
        if (a == 1) {
            for (auto &i : v) cout << i <<  ' ';
            cout << "1\n";
        }
        else cout << "Boring!\n";
    }
}