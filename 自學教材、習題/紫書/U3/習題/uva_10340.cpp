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
    string a, b;
    while (cin >> a >> b) {
        int j = 0;
        for (int i = 0; i < b.size(); i++) if (a[j] == b[i]) {
            j++;
            if (j == a.size()) break;
        }
        if (j == a.size()) cout << "Yes\n";
        else cout << "No\n";
    }
}