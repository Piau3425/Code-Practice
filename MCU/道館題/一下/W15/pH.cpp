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
#define TIII tuple<int, int, int>

signed main() { WA();
    string s; int a, b, k;
    priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
    while (cin >> s, s != "#") {
        cin >> a >> b;
        pq.push({b, a, b});
    }
    cin >> k;
    while (k--) {
        auto [a, b, c] = pq.top(); pq.pop();
        cout << b << '\n';
        pq.push({a+c, b, c});
    }
}