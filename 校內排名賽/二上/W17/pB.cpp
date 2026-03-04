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

int mx[] = {-1, 0, 1, 0}, my[] = {0, 1, 0, -1};

signed main() { WA();
    int t;
    for (cin >> t; t--;) {
        int n, m; cin >> n >> m; cin.ignore();
        vector<string> v(n);
        for (auto &i : v) getline(cin, i);
        int x, y, dir = 0; cin >> x >> y; x--, y--;

        for (char c; cin >> c, c != 'Q';) {
            if (c == 'L') dir = (dir+3)%4;
            else if (c == 'R') dir = (dir+1)%4;
            else {
                int nx = x+mx[dir], ny = y+my[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '*') x = nx, y = ny;
            }
        }
        cout << x+1 << ' ' << y+1 << ' ' << "NESW"[dir] << '\n';
        if (t) cout << '\n';
    }
}