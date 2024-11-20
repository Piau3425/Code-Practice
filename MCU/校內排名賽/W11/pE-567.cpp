#include <bits/stdc++.h>
using namespace std;
#define int long long
#define WA() ios::sync_with_stdio(0);cin.tie(0)

signed main() { WA();
	int t = 0, n, j, a, b;;
	while (cin >> n) {
		vector<vector<int>> g(21);
		for (int i = 1; i <= 19; i++) {
			if (i > 1) cin >> n;
			while (n--) {
				cin >> j;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		
		cout << "Test Set #" << ++t << '\n';
		cin >> n;
		while (n--) {
			cin >> a >> b;
			cout << setw(2) << a << " to " << setw(2) << b << ":";
			queue<pair<int, int>> q;
			q.push({a, 0});
			while (q.size()) {
				auto d = q.front(); q.pop();
				if (d.first == b) {
					cout << setw(2) << d.second;
					break;
				}
				for (auto u : g[d.first]) q.push({u, d.second+1});
			}
			cout << '\n';
		}
		cout << '\n';
	}
}