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

signed main() {
    int n; cin >> n;
    vector<pair<string, int>> v(n);
    int sum = 0;
    for (auto &i : v) cin >> i.fi >> i.se, sum += i.se;
    sort(all(v));
    for (auto &i : v) cout << i.fi << "(" << fixed << setprecision(2) << (double)i.se/sum << ")\n"; //printf("%s(%.2llf)\n", i.fi.data(), (double)i.se/sum);
}