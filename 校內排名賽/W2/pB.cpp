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
    string s; cin >> s; cin.ignore();
    int mx = -1e9;
    vector<int> v(26);
    while (getline(cin, s)) for (auto &c : s) if (isalpha(c)) mx = max(++v[toupper(c)-'A'], mx);
    for (int i = mx; mx; mx--) for (int j = 0; j < 26; j++) if (v[j] == mx) cout << char(j+'A') << ' ' << mx << '\n';
}