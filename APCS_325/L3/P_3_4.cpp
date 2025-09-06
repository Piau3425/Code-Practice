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
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    v[0] = INF;
    stack<int> sk; sk.push(0);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        while (v[sk.top()] <= v[i]) sk.pop();
        sum += i - sk.top();
        sk.push(i);
    }
    cout << sum;
}