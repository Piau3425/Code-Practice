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
    int n; cin >> n; queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    while (q.size()) {
        q.push(q.front()); q.pop();
        cout << q.front() << ' '; q.pop();
    }
}