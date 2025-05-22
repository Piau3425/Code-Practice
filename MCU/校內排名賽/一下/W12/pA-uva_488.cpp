#include <bits/stdc++.h>
using namespace std;

main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		while (b--) {
			for (int i = 1; i <= a; i++) cout << string(i, i+'0') << '\n';
			for (int i = a-1; i > 0; i--) cout << string(i, i+'0') << '\n';
			if (b) cout << '\n';
		}
		if (t) cout << '\n';
	}
}