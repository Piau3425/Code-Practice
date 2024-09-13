#include <bits/stdc++.h>
using namespace std;

// 50%

int n, m;

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < m && y < n;
}

int main() {
	int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1}, cnt = 1;
	bool f = false;
	while (cin >> n >> m && n && m) {
		if (f) cout << '\n';
		cout << "Field #" << cnt++ << ":\n";
		vector<vector<char>> v(n, vector<char>(m));
		for (auto &i : v) for (auto &j : i) cin >> j;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == '*') cout << '*';
				else {
					int sum = 0;
					for (int k = 0; k < 8; k++) if (check(i+dx[k], j+dy[k])) sum += v[i+dx[k]][j+dy[k]] == '*';
					cout << sum;
				}
			}
			cout << '\n';
		}
		f = true;
	}
}