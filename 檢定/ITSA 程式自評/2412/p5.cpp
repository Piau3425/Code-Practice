#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n, k;
    cin >> n >> k;
    vector<tuple<int, int, int>> v(n);
    int idx = 1;
    for (auto &[a, b, c] : v) {
        cin >> a >> b;
        c = idx++;
    }
    sort(all(v), greater<tuple<int, int, int>>());
    v.erase(v.begin()+k, v.end());
    for (auto &[a, b, c] : v) swap(a, b);
    sort(all(v), greater<tuple<int, int, int>>());
    cout << get<2>(v[0]) << '\n';   
}