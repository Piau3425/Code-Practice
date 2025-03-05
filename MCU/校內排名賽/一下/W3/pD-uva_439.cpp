#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() {
    string a, b;
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    while (cin >> a >> b) {
    	vector<vector<int>> vis(8, vector<int>(8));
    	queue<tuple<int, int, int>> q;
    	int sy = a[0]-'a', sx = a[1]-1-'0', ans = 0;
    	q.push({sy, sx, 0});

    	while (!q.empty()) {
    		auto [y, x, step] = q.front(); q.pop();
    		if (vis[y][x]) continue;
    		vis[y][x] = 1;

    		if (y == b[0]-'a' && x == b[1]-1-'0') {
    			ans = step;
    			break;
    		}
    		
    		for (int i = 0; i < 8; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) q.push({ny, nx, step+1});
    		}
    	}

    	cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves.\n";
    }
}