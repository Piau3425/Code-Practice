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
    int n; cin >> n; cin.ignore();
    while (n--) {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        for (auto &c : a) if (!isalpha(c)) c = ' ';
        for (auto &c : b) if (!isalpha(c)) c = ' ';
        stringstream aa(a), bb(b);
        set<string> sa, sb;
        while (aa >> a) sa.insert(a);
        while (bb >> b) sb.insert(b);
        int cnt = 0;
        for (auto &i : sa) if (!sb.count(i)) cnt++;
        for (auto &i : sb) if (!sa.count(i)) cnt++;
        cout << cnt << '\n';
    }
}