#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, cnt = 1;
	while (cin >> n) {
		vector<int> v(n);
		map<int, int> mp;
		for (auto &i : v) cin >> i;
		
		for (int i = 0; i < n; i++) for (int j = i; j < n; j++) mp[v[i]+v[j]]++;
		
		bool f = true;
		for (auto i : mp) if (i.second > 1) f = false;
		cout << "Case #" << cnt++ << ": ";
		if (f) cout << "It is a B2-Sequence.\n\n";
		else cout << "It is not a B2-Sequence.\n\n";
	}
}