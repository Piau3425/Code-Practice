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
        queue<int> now, disc;
        for (int i = 1; i <= n; i++) now.push(i);
        while (now.size() > 1) {
            disc.push(now.front()); now.pop();
            now.push(now.front()); now.pop();
        }
        cout << "Discarded cards:";
        if (disc.empty()) cout << '\n';
        while (disc.size()) cout << ' ' << disc.front() << ",\n"[disc.size() == 1], disc.pop();
        cout << "Remaining card: " << now.front() << '\n';
    }
}