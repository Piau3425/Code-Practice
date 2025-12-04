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
    string s;
    int n; cin >> n;
    while (n--) {
        cin >> s;
        if (abs((s[0]-'A')*26*26+(s[1]-'A')*26+s[2]-'A' - stoi(s.substr(4))) <= 100) cout << "nice\n";
        else cout << "not nice\n";
    }
}