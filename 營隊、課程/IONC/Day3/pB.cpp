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

int n;
vector<vector<char>> v;

int dfs(int x, int y) {
    if (x == n-1 && y == n-1) return 1;
    int ans = 0;
    if (x+1 >= 0 && x+1 < n && v[x][y] != '*') ans += dfs(x+1, y);
    if (y+1 >= 0 && y+1 < n && v[x][y] != '*') ans += dfs(x, y+1);
    return ans;
}

signed main() { WA();
    cin >> n;
    v.resize(n, vector<char>(n));
    for (auto &i : v) for (auto &j : i) cin >> j;
    cout << dfs(0, 0) << '\n';
}