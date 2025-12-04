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
    int n;
    while (cin >> n, n) {
        vector<string> v(n);
        for (auto &i : v) cin >> i;
        sort(all(v), [](string a, string b){return a+b > b+a;});
        for (auto &i : v) cout << i; cout << '\n';
    }
}