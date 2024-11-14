#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<pair<int, string>> v;
    while (n--) {
        string s;
        int a, b, c, d, e, f;
        cin >> s >> a >> b >> c >> d >> e >> f;
        //cout << s << ' ' << a << ' ' << b  << ' ' << c << ' ' << d << ' ' << e << '\n';
        v.push_back({(1000+(a-170)*100+(b+c+d+e+f)*20), s});
    }
    sort(all(v), greater<pair<int, string>>());
    for (auto i : v) cout << i.second << '\n';
}