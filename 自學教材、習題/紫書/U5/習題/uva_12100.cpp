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
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        priority_queue<int> pq;
        queue<PII> q;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            pq.push(k); q.push({k, i});
        }

        int min = 0;
        while (1) {
            if (q.front().fi == pq.top() && q.front().se == m) break;
            else if (q.front().fi == pq.top()) q.pop(), pq.pop(), min++;
            else q.push(q.front()), q.pop();
        }

        cout << min+1 << '\n';
    }
}