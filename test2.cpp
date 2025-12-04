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

int dx[] = {0, -1, 1, 0}, dy[] = {-1, 0, 0, 1};

signed main() { WA();
	int n; cin >> n;
	vector<vector<pair<char, bool>>> v(n, vector<pair<char, bool>>(n));
	for (auto &i : v) for (auto &j : i) cin >> j.fi;
	int sy, sx;
	while (cin >> sy >> sx) {
		cout << "BFS " << v[sy][sx].fi << ": ";
		queue<PII> q; q.push({sy, sx});
		while (q.size()) {
			auto [y, x] = q.front(); q.pop();
			if (v[y][x].se) continue;
			v[y][x].se = true;
			cout << v[y][x].fi;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny >= 0 && ny < n && nx >= 0 && nx < n) q.push({ny, nx});
			}
		}
		for (auto &i : v) for (auto &j : i) j.se = false;
		cout << '\n';

		cout << "DFS " << v[sy][sx].fi << ": ";
		stack<PII> s; s.push({sy, sx});
		while (s.size()) {
			auto [y, x] = s.top(); s.pop();
			if (v[y][x].se) continue;
			cout << v[y][x].fi;
			v[y][x].se = true;
			for (int i = 0; i < 4; i++) {
			//for (int i = 4; i >= 0; i--) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny >= 0 && ny < n && nx >= 0 && nx < n) s.push({ny, nx});
			}
		}
		for (auto &i : v) for (auto &j : i) j.se = false;
		cout << "\n\n";
	}
}