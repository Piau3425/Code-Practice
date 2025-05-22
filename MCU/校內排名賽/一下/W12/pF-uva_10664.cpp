#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int ck, sz, sa, sb;
vector<int> v;

void dfs(int x) {
	if (x == sz) {
		if (sa == sb) ck = 1;
		return;
	}
	sa += v[x];
	dfs(x+1);
	sa -= v[x];
	sb += v[x];
	dfs(x+1);
	sb -= v[x];
}

main() {
	int t; cin >> t; cin.ignore();
	while (t--) {
		sa = 0, sb = 0;
		v.clear();
		ck = 0;
		string s;
		getline(cin, s); stringstream ss(s);
		int n;
		while(ss >> n) v.pb(n);
		sz = v.size();
		dfs(0);
		if (ck) cout << "YES\n";
		else cout << "NO\n";
	}
}