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
    for (int n; cin >> n, cin.ignore();) {
        string s; getline(cin, s);
        stringstream ss(s);
        vector<int> v;
        int k, sum = 0;
        while (ss >> k) v.pb(k); v.pop_back();
        for (int i = 0; i < v.size(); i++) sum = sum * n + v[i]*(v.size()-i);
        cout << sum << '\n';
    }
}