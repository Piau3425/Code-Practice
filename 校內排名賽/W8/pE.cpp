#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIII tuple<int, int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<string> maze;

void dfs(int x, int y) {
    maze[x][y] = '#';
    int mx[] = {1, 0, -1, 0}, my[] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
        int nx = x+mx[i], ny = y+my[i];
        if (nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[nx].size() && maze[nx][ny] == ' ') {
            dfs(nx, ny);
        }
    }
}

signed main() { WA();
    int n; for (cin >> n, cin.ignore(); n--;) {
        maze.clear();
        string s;
        int sx, sy;
        while (getline(cin, s), s.front() != '_') {
            maze.pb(s);
            if (s.find('*') != string::npos) sx = maze.size()-1, sy = s.find('*');
        }
        dfs(sx, sy);
        for (auto &i : maze) cout << i << '\n';
        cout << s << '\n';
    }
}