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
    string s, a, b;
    getline(cin, s);
    cin >> a >> b;
    for (int pos = 0; (pos = s.find(a, pos)) != string::npos; pos += b.size()) s.replace(pos, a.size(), b);
    cout << s << '\n';
}