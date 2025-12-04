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
    int n;
    while (cin >> n, n) {
        int t, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        while (n--) cin >> t, pq.push(t);
        while (pq.size() != 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            sum += a + b;
            pq.push(a+b);
        }
        cout << sum << '\n';
    }
}