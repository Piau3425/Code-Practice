#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<vector<int>> v;
vector<int> co;
int ck;

void dfs(int x) {
	for (auto u : v[x]) {
		if (co[u]) {
			if (co[x] == co[u]) ck = 0;
		    continue;
		}
		
		co[u] = 3 - co[x];
		dfs(u);
	}
}

main() {
	int n, m;
	while (cin >> n >> m) {
		v.resize(n);
		co.assign(n, 0);
		while (m--) {
			int a, b;
			cin >> a >> b;
			v[a].pb(b);
			v[b].pb(a);
		}
		
		co[0] = 1;
		ck = 1;
		dfs(0);
		if(ck) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
		
		v.clear();
	}
}