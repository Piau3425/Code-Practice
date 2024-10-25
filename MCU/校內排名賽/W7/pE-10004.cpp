#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b, valid;
vector<vector<int>> g;
vector<int> c;

void dfs(int v) {
	for (auto u : g[v]) {
		if (c[u]) {
			if (c[u] == c[v]) {
				valid = 0;
				return;
			}
			continue;
		}
		c[u] = 3 - c[v];
		dfs(u);
	}
}

signed main() {
	while (cin >> n >> m, n) {
		valid = 1;
		g.resize(n); c.resize(n, 0);
		while (m--) {
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		
		for (int i = 0; i < n; i++) {
			if (c[i]) continue;
			c[i] = 1;
			dfs(i);
		}
		if (valid) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
		g.clear(); c.clear();
	}
}