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

int n, cnt = 0;
vector<int> v;
vector<pair<int, int>> g;

void dfs(int lv, int to) {
    for (int i = lv; i; i--) {
        if (v[i] != to) {
            dfs(i-1, 6-v[i]-to);
            g.pb({v[i], to});
            v[i] = to;
            cnt++;
        }
    }
}

signed main() { WA();
    cin >> n;
    v.assign(n+1, 1);   
    dfs(n, 3);
    cout << cnt << '\n';
    for (auto i : g) cout << i.fi << ' ' << i.se << '\n';
}