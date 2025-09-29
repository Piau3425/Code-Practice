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
    int n; cin >> n;
    vector<int> deg(n+1), h(n+1), par(n+1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        cin >> deg[i];
        if (!deg[i]) q.push(i);
        for (int t = deg[i]; t; t--) {
            int k; cin >> k;
            par[k] = i;
        }
    }
    int sum = 0;
    while (par[q.front()]) {
        int now = q.front(); q.pop();
        sum += h[now];
        h[par[now]] = max(h[now]+1, h[par[now]]);
        if (!(--deg[par[now]])) q.push(par[now]);
    }
    cout << q.front() << '\n' << sum+h[q.front()] << '\n';
}