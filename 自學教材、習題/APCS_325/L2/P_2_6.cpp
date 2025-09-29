#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, m, k;
    cin >> n >> m >> k;
    set<int> a, b;
    while (n--) {
        int g; cin >> g;
        a.insert(g);
    }
    while (m--) {
        int g; cin >> g;
        b.insert(g);
    }
    int cnt = 0;
    for (auto &i : a) if (b.count(k-i)) cnt++;
    cout << cnt;
}