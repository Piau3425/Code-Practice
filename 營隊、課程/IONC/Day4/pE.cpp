#include <bits/stdc++.h>
using namespace std;

#define WA() cin.tie(0)->sync_with_stdio(0)

unsigned a[1000001], p[1000001], w[1000001];

signed main() { WA();
    unsigned n; cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) w[p[i]]++;
    queue<int> q;
    unsigned long long sum = 0;
    for (int i = 1; i <= n; i++) if (!w[i]) q.push(i);
    while (q.size()) {
        sum += a[q.front()];
        a[p[q.front()]] = min(a[p[q.front()]], a[q.front()]);
        if (!(--w[p[q.front()]])) q.push(p[q.front()]);
        q.pop();
    }
    cout << sum;
}