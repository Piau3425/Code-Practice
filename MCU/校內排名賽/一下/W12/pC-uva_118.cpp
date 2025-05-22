#include <bits/stdc++.h>
using namespace std;

main() {
	int n, m; cin >> n >> m;
	int x, y, dir; char tmp; string move;
	vector<vector<int>> v(m+1, vector<int>(n+1, 0));
	while (cin >> x >> y >> tmp >> move) {
		string ee = "NESW";
		int mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0};
		bool notlost = 1;
		dir = ee.find(tmp);
		for (auto &c : move) {
			if (c == 'R') dir = (dir+1)%4;
			else if (c == 'L') dir = (dir+3)%4;
			else {
				int nx = x + mx[dir], ny = y + my[dir];
				if (nx >= v[0].size() || nx < 0 || ny >= v.size() || ny < 0) { 
					if (v[y][x]) continue;
					notlost = 0;
					v[y][x] = 1;
					cout << x << ' ' << y << ' ' << ee[dir] << " LOST\n";
					break;
				}
				x = nx, y = ny;
			}
		}
		if (notlost) cout << x << ' ' << y << ' ' << ee[dir] << '\n';
	}
}