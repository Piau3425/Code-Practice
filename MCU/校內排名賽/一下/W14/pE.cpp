#include <iostream>
using namespace std;

main() {
	int n, m, T = 0;
	while (cin >> n >> m, n+m) {
		int v[n+1][m+1] = {}, a[n] = {}, b[m] = {};
		for (auto &i : a) cin >> i;
		for (auto &i : b) cin >> i;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1]+1;
				else v[i][j] = max(v[i-1][j], v[i][j-1]);
			}
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++T, v[n][m]);
	}
}