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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    map<int, int> mp;
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (auto &i : a) for (auto &j : b) if (j-i >= 0) mp[j-i]++;
    cout << max_element(all(mp), [](PII a, PII b){
        return a.se < b.se;
    })->fi;
}