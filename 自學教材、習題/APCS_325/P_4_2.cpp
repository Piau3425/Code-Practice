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
    vector<priority_queue<int, vector<int>, greater<int>>> v(2);
    int n, i = 0, j;
    for (cin >> n; i < 2; i++) for (j = n; j; j--) {
        int k; cin >> k;
        v[i].push(k);
    }
    int ans = 0;
    while (v[1].size()) {
        if (v[1].top() > v[0].top()) {
            v[0].pop();
            ans++;
        }
        v[1].pop();
    }
    cout << ans;
}