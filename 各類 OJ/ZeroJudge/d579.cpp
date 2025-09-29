#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	for (cin >> t; t; t--) {
		int n, p, day = 6, ans = 0;
		cin >> n >> p;
		vector<int> v(p);
		for (auto &i : v) cin >> i;
		for (int i = 1; i <= n; i++, day = (day+1)%7) {
			if (day == 4 || day == 5) continue;
			int f = 0;
			for (auto j : v) f += !(i%j);
			if (f) ans++;
		}
		cout << ans << '\n';
	}
}