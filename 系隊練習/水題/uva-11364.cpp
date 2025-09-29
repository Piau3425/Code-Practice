#include <bits/stdc++.h>
using namespace std;

main() {
	int n, t; cin >> t;
	while (t--) {
		cin >> n;
		vector<int> v(n);
		for (auto &i : v) cin >> i;
		sort(v.begin(), v.end());
		cout << 2*(v.back()-v.front()) << endl;
	}
}