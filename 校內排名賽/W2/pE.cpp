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

vector<int> coin = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

signed main() { WA();
    vector<int> v(30000+1); v[0] = 1;
    for (auto c : coin) for (int i = c; i < v.size(); i++) v[i] += v[i-c];

    for (double n; cin >> n, round(n*100);) cout << setw(6) << fixed << setprecision(2) << n << setw(17) << v[round(n*100)] << '\n';
}