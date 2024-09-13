#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l;
	for (cin >> n; n; n--) {
		cin >> l;
		vector<int> v(l);
		int ans = 0;
		for (auto &i : v) cin >> i;
		for (int i = 0; i < l-1; i++)
			for (int j = 0; j < l-1-i; j++)
				if (v[j] > v[j+1]) {
					swap(v[j], v[j+1]);
					ans++;
				}
		cout << "Optimal train swapping takes " << ans << " swaps.\n";
	}
}