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

vector<pair<string, int>> v = {
    {"kuti", 10000000},
    {"lakh", 100000},
    {"hajar", 1000},
    {"shata", 100}
};

void f(int x) {
    if (x >= 10000000) {
        f(x/10000000);
        cout << " kuti";
        x %= 10000000;
    }
    for (auto &[str, n] : v) {
        if (x >= n) {
            cout << " " << x/n << " " << str;
            x %= n;
        }
    }
    if (x > 0) cout << ' ' << x;
}

signed main() { WA();
    int T = 0;
    for (int n; cin >> n;) {
        cout << setw(4) << ++T << ".";
        if (n) f(n), cout << '\n';
        else cout << " 0\n";
    }
}