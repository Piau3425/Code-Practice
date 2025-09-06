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
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        int mx = *max_element(all(v));

        int tmp = 1;
        vector<priority_queue<int, vector<int>, greater<int>>> g(mx+1);
        for (int i = 0; i < mx; i++) {
            int k = count(all(v), mx-i);
            while (k--) g[i].push(tmp);
            if (g[i].size() == 1) g[i+1].push(g[i].top()), g[i].pop();
            else while (g[i].size()) {
                int sum = g[i].top(); g[i].pop();
                sum += tmp = g[i].top(), g[i].pop();
                g[i+1].push(sum);
            }
            cout << g[i+1].top() << ' ';
        }
        cout << g[mx].top() << '\n';
    }
}